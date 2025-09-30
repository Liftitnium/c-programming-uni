# included by src/CMakeLists.txt
file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} [0-9]-*)
foreach(child ${children})
  if (IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
    add_subdirectory(${child})
  endif()
endforeach()