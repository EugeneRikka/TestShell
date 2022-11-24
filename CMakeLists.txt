cmake_minimum_required(VERSION 3.24)
project(TestShell)

set(CMAKE_CXX_STANDARD 20)

add_executable(KITe src/main.cpp)

enable_testing()
set(TESTS_DIR ${PROJECT_SOURCE_DIR}/tests)
add_subdirectory(testShell)