cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
# Multi-Language Vulkan/GL/GLES/EGL/GLX/WGL Loader-Generator based on
# the official specs. http://glad.dav1d.de/
FetchContent_Declare(
  extern_glad

  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG        v0.1.27)

FetchContent_GetProperties(extern_glad)
if(NOT extern_glad_POPULATED)
  FetchContent_Populate(extern_glad)

  set(GLAD_INSTALL ON)
  add_subdirectory(
    ${extern_glad_SOURCE_DIR}
    ${extern_glad_BINARY_DIR}
    EXCLUDE_FROM_ALL)
endif()