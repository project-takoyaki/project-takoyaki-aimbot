#include "obs_hook.hpp"

#include <VirtualizerSDK.h>

namespace takoyaki::obs_hook {
  bool copy_texture_hook::install() {
    return m_copy_texture_detour->hook();
  }

  bool copy_texture_hook::uninstall() {
    m_device = nullptr;
    m_device_context = nullptr;
    return m_copy_texture_detour->unHook();
  }

  bool copy_texture_hook::installed() {
    return m_copy_texture_detour->isHooked();
  }

  void copy_texture_hook::copy_texture_callback(void* gs_duplicator, ID3D11Texture2D* texture) {
    VIRTUALIZER_MUTATE_ONLY_START;

    std::call_once(m_device_initialization_flag, [&]() {
      texture->GetDevice(&m_device);
      m_device->GetImmediateContext(&m_device_context);
    });

    D3D11_TEXTURE2D_DESC texture_description;
    texture->GetDesc(&texture_description);

    texture_description.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    texture_description.Usage = D3D11_USAGE_STAGING;
    texture_description.BindFlags = 0;
    texture_description.MiscFlags = 0;

    Microsoft::WRL::ComPtr<ID3D11Texture2D> staging_texture;
    if (m_device->CreateTexture2D(&texture_description, nullptr, &staging_texture) != S_OK) {
      PLH::FnCast(m_copy_texture_trampoline_address, reinterpret_cast<void(*)(void*, ID3D11Texture2D*)>(m_copy_texture_address))(gs_duplicator, texture);
      return;
    }

    m_device_context->CopyResource(staging_texture.Get(), texture);

    D3D11_MAPPED_SUBRESOURCE mapped_subresource;
    if (m_device_context->Map(staging_texture.Get(), 0, D3D11_MAP_READ, 0, &mapped_subresource) != S_OK) {
      PLH::FnCast(m_copy_texture_trampoline_address, reinterpret_cast<void(*)(void*, ID3D11Texture2D*)>(m_copy_texture_address))(gs_duplicator, texture);
      return;
    }

    auto texture_data = static_cast<uint8_t*>(mapped_subresource.pData);

    m_device_context->UpdateSubresource(texture, 0, nullptr, mapped_subresource.pData, mapped_subresource.RowPitch, 0);

    m_device_context->Unmap(staging_texture.Get(), 0);

    PLH::FnCast(m_copy_texture_trampoline_address, reinterpret_cast<void(*)(void*, ID3D11Texture2D*)>(m_copy_texture_address))(gs_duplicator, texture);

    VIRTUALIZER_MUTATE_ONLY_END;
  }
}