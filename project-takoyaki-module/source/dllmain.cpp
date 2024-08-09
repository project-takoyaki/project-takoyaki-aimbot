#include <chrono>
#include <thread>

#include <Windows.h>

#include "obs_hook.hpp"

void takoyaki_main() {
  AllocConsole();
  FILE* file;
  freopen_s(&file, "CONOUT$", "w", stdout);

  takoyaki::obs_hook::copy_texture_hook::install();
}

BOOL APIENTRY DllMain(HMODULE, DWORD reason, LPVOID) {
  if (reason == DLL_PROCESS_ATTACH) {
    std::thread(takoyaki_main).detach();
  }

  return TRUE;
}