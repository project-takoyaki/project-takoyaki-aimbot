cmake_minimum_required(VERSION 3.13.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(project-takoyaki-firmware LANGUAGES C)

target_include_directories(app PRIVATE src)
target_sources(app PRIVATE
  src/main.c
)
