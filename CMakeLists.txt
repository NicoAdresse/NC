# CMakeLists.txt

#   SPDX-License-Identifier: MIT
#   Copyright (c) 2026 Nico Erdmann
#   CMakeLists.txt for NC

# CMakeLists.txt

#   SPDX-License-Identifier: MIT
#   Copyright (c) 2026 Nico Erdmann
#   CMakeLists.txt for NC

cmake_minimum_required(VERSION 3.12)
project(nc VERSION 1.0.0 LANGUAGES C)

if(CMAKE_C_COMPILER_ID MATCHES "MSVC")
    message(FATAL_ERROR "Compilation failed: MSVC is explicitly NOT supported due to reliance on GCC/Clang extensions.")
elseif(CMAKE_C_COMPILER_ID MATCHES "IntelLLVM")
    message(STATUS "Compiler verified: Intel OneAPI ICX (${CMAKE_C_COMPILER_VERSION})")
map_test_pm(IntelLLVM)
elseif(CMAKE_C_COMPILER_ID MATCHES "Clang|AppleClang")
    message(STATUS "Compiler verified: Clang (${CMAKE_C_COMPILER_VERSION})")
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
    message(STATUS "Compiler verified: GCC (${CMAKE_C_COMPILER_VERSION})")
else()
    message(FATAL_ERROR "Compilation failed: Unsupported compiler '${CMAKE_C_COMPILER_ID}'. Only GCC, Clang, and ICX are permitted.")
endif()

add_library(nc INTERFACE)
add_library(nc::nc ALIAS nc)

target_include_directories(nc INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(DIRECTORY src/nc DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS nc EXPORT ncTargets)
install(EXPORT ncTargets
    FILE ncTargets.cmake
    NAMESPACE nc::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/nc
)
