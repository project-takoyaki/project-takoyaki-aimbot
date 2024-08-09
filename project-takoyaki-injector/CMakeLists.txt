add_executable(project-takoyaki-injector
  # Source files
  source/information.cpp
  source/main.cpp

  # Header files
  include/information.hpp
)

target_include_directories(project-takoyaki-injector PRIVATE
  include
)

set_target_properties(project-takoyaki-injector PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)