cmake_minimum_required(VERSION 3.7)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(lisp-cpp-interop
  VERSION 1.0
  DESCRIPTION "simple example of calling cpp code from (sbcl) lisp code"
  LANGUAGES CXX)

set(default_build_type "Debug")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(lib SHARED)
target_sources(lib PRIVATE lib.cpp)
