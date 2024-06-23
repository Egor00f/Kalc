cmake_minimum_required(VERSION 3.10)

project(Kalc)


set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#include(CMakeLoadToolchainPath)
#include(CMakeKOS32gcc)



add_executable(Kalc src/main.cpp)

set(KolibriOS_Repo_dir "../kolibrios")

include_directories(${KolibriOS_Repo_dir}/contrib/sdk/sources/newlib/include)
include_directories(${KolibriOS_Repo_dir}/contrib/sdk/sources/libstdc++-v3/include)

#add KolibriLib
add_subdirectory(KolibriOS-Cpp-Lib)
include_directories(KolibriOS-Cpp-Lib/include)
target_link_libraries(Kalc KolibriLib)

#add tinyexpr
add_subdirectory(tinyexpr)
include_directories(tinyexpr)
target_link_libraries(Kalc tinyexpr)