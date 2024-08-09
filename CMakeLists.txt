cmake_minimum_required(VERSION 3.28)

project(project-takoyaki)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 26)
set(ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(VIRTUALIZER_DIRECTORY ${ROOT_DIRECTORY}/dependencies/libraries/Virtualizer)

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(TARGET_ARCHITECTURE "x64")
  set(VIRTUALIZER_LIBRARY VirtualizerSDK64)
elseif (CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(TARGET_ARCHITECTURE "x86")
  set(VIRTUALIZER_LIBRARY VirtualizerSDK32)
endif ()

add_subdirectory(dependencies)
add_subdirectory(project-takoyaki-injector)
add_subdirectory(project-takoyaki-module)