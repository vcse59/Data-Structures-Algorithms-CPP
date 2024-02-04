cmake_minimum_required(VERSION 3.0.0)
project(executable VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(executable src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_BUILD_TYPE Debug)
include(CPack)
