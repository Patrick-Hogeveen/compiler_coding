cmake_minimum_required(VERSION 3.22)
project(llvm_playground) 
find_package(LLVM REQUIRED CONFIG)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
include(AddLLVM)
 
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_llvm_executable(main main.cpp)
target_include_directories(main PUBLIC ${LLVM_INCLUDE_DIRS})