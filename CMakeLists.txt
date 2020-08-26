cmake_minimum_required(VERSION 3.17.1)
project(alpha_fds)

set (CMAKE_C_FLAGS_INIT                "-Wall -std=c99")
set (CMAKE_C_FLAGS_DEBUG_INIT          "-g")
set (CMAKE_C_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
set (CMAKE_C_FLAGS_RELEASE_INIT        "-O4 -DNDEBUG")
set (CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS_INIT                "-Wall -Wno-overflow -pendantic -std=c++2a")
set (CMAKE_CXX_FLAGS_DEBUG_INIT          "-g --stdlib=libstdc++")
set (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
set (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O4 -DNDEBUG")
set (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")
set (CMAKE_CXX_FLAGS "-fPIC")

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(TEST_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test)

file(GLOB SOURCES "src/*.cxx")

find_package(GTK2 2.10 REQUIRED gtk)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB2 REQUIRED glib-2.0)
pkg_check_modules(GSTREAMER1 REQUIRED gstreamer-1.0)

enable_testing()
add_subdirectory(src)
