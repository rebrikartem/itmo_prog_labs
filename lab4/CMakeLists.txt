cmake_minimum_required(VERSION 3.14)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 3.3 REQUIRED)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${GLUT_INCLUDE_DIRS} )
include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(extern)


target_link_libraries(lab4_run glfw)
target_link_libraries(lab4_lib glfw)
target_link_libraries(lab4_lib OpenGL::GL)
target_link_libraries(lab4_run OpenGL::GL)
target_link_libraries(lab4_run GLEW::GLEW)
target_link_libraries(lab4_lib GLEW::GLEW)

target_link_libraries(lab4_run "-framework GLUT")
target_link_libraries(lab4_lib "-framework GLUT")

target_link_libraries(lab4_run
  glad
  ${CMAKE_DL_LIBS})

  target_link_libraries(lab4_lib
  glad
  ${CMAKE_DL_LIBS})
