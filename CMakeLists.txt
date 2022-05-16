cmake_minimum_required(VERSION 3.0.0)
project(hisstools_cmake_proj VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(hisstools_cmake_proj hisstools_cmake_proj.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
