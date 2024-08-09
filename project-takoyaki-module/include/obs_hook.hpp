#pragma once

#include <mutex>

#include <d3d11.h>

#include <wrl/client.h>

#include <polyhook2/Detour/NatDetour.hpp>

namespace takoyaki::obs_hook {
  class copy_texture_hook {
    public:
      static bool install();
      static bool uninstall();
      static bool installed();

    private:
      static constexpr uintptr_t COPY_TEXTURE_OFFSET = 0x1B20;

      static inline uintptr_t m_copy_texture_address = reinterpret_cast<uintptr_t>(GetModuleHandle("libobs-d3d11.dll")) + COPY_TEXTURE_OFFSET;
      static inline uintptr_t m_copy_texture_trampoline_address = 0x0;

      static inline std::once_flag m_device_initialization_flag;
      static inline Microsoft::WRL::ComPtr<ID3D11Device> m_device;
      static inline Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_device_context;

      static void copy_texture_callback(void* gs_duplicator, ID3D11Texture2D* texture);
      inline static auto m_copy_texture_detour = std::make_unique<PLH::NatDetour>(m_copy_texture_address, reinterpret_cast<uintptr_t>(copy_texture_callback), &m_copy_texture_trampoline_address);
  };
}