add_library(project-takoyaki-module SHARED
  # Source files
  source/dllmain.cpp
  source/information.cpp
  source/obs_hook.cpp

  # Header files
  include/information.hpp
  include/obs_hook.hpp
)

target_include_directories(project-takoyaki-module PRIVATE
  ${VIRTUALIZER_DIRECTORY}/include
  include
)

target_link_libraries(project-takoyaki-module PRIVATE
  ${VIRTUALIZER_DIRECTORY}/lib/${TARGET_ARCHITECTURE}/${VIRTUALIZER_LIBRARY}.lib
  PolyHook_2
)

set_target_properties(project-takoyaki-module PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(TARGET project-takoyaki-module POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${VIRTUALIZER_DIRECTORY}/bin/${TARGET_ARCHITECTURE}/${VIRTUALIZER_LIBRARY}.dll $<TARGET_FILE_DIR:project-takoyaki-module>
)