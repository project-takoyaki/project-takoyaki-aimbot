#include <chrono>
#include <thread>

#include <Windows.h>

#include <VirtualizerSDK.h>
#include <VirtualizerSDK_TIGER_LONDON.h>

#include "obs_hook.hpp"

void takoyaki_main() {
  VIRTUALIZER_TIGER_LONDON_START;

  AllocConsole();
  FILE* file;
  freopen_s(&file, "CONOUT$", "w", stdout);

  takoyaki::obs_hook::copy_texture_hook::install();

  VIRTUALIZER_TIGER_LONDON_END;
}

BOOL APIENTRY DllMain(HMODULE, DWORD reason, LPVOID) {
  VIRTUALIZER_TIGER_LONDON_START;

  if (reason == DLL_PROCESS_ATTACH) {
    std::thread(takoyaki_main).detach();
  }

  VIRTUALIZER_TIGER_LONDON_END;

  return TRUE;
}