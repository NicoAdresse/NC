# CMakeLists.txt

#   SPDX-License-Identifier: MIT
#   Copyright (c) 2026 Nico Erdmann
#   CMakeLists.txt for NC

cmake_minimum_required(VERSION 3.12)
project(nc VERSION 1.0.0 LANGUAGES C)

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