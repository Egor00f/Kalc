CMAKE_MINIMUM_REQUIRED(VERSION 3.19)

project(
    Kalc
    VERSION 0.0.1
    DESCRIPTION "Calculator for KolibriOS"
    LANGUAGES CXX
)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/KolibriOS-Cpp-Lib/cmake")

set(KOLIBRIOS_REPO	${CMAKE_CURRENT_SOURCE_DIR}/../kolibrios)



set(CMAKE_CXX_STANDARD 11)


include(CMakeDetermineKOS32Compiler)
include(CMakeTestKOS32Compiler)

add_subdirectory(tinyexpr)
add_subdirectory(KolibriOS-Cpp-Lib)


set(CMAKE_C_FLAGS_DEBUG "-Wall -Wextra -Wcast-align -Wcast-qual -Wconversion -Wenum-compare -Wfloat-equal -Wredundant-decls -Wsign-conversion -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wctor-dtor-privacy -Wnon-virtual-dtor -Wsign-promo -Wold-style-cast -Woverloaded-virtual")

set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

add_executable(Kalc src/main.cpp)

target_link_libraries(Kalc 
    PUBLIC KolibriLib
    PUBLIC tinyexpr
)

add_custom_command(
	TARGET Kalc POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} ARGS Kalc -O binary
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)