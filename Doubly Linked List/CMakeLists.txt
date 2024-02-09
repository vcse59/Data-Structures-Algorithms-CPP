cmake_minimum_required(VERSION 3.10.0)
project(executable VERSION 0.1.0 LANGUAGES C CXX)

include(CTest include)
enable_testing()

set( SOURCE_FILES src/sample.cpp)

add_library(Doublylinkedlist SHARED ${SOURCE_FILES})

set_target_properties(Doublylinkedlist PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(executable src/main.cpp)

target_link_libraries(executable Doublylinkedlist)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
