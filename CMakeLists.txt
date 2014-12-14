#
# This file is part of the krnl4
# Copyright (C) 2014 Aleksandar Dezelin <dezelin@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required (VERSION 2.8)

set (CODENAME "krnl4")
set (COPYRIGHT_YEARS "2014")
set (VERSION_MAJOR 0)
set (VERSION_MINOR 0)
set (VERSION_PATCH 1)
set (VERSION_TYPE SNAPSHOT)
set (VERSION_STRING
    "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}-${VERSION_TYPE}"
)

# Don't start build from the root directory
if (CMAKE_BINARY_DIR STREQUAL ${CMAKE_SOURCE_DIR})
  message(FATAL_ERROR "type: git clean -df && mkdir build && cd build && cmake .. && make")
endif ()

# Set CMake modules path
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

# Set make files verbosity
if (CMAKE_BUILD_TYPE MATCHES Debug)
  set (CMAKE_VERBOSE_MAKEFILE 1)
  option (__DEBUG__ "Debug build" ON)
else ()
  set (CMAKE_VERBOSE_MAKEFILE 0)
  option (__DEBUG__ "Debug build" OFF)
endif ()

message ("-- Architecture: " ${CMAKE_SYSTEM_PROCESSOR})

# Set root arch and include dirs
set (ARCH_DIR ${CMAKE_SOURCE_DIR}/arch)
set (INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Set asm arch and include dirs
set (ARCH_ASM_DIR ${CMAKE_BINARY_DIR}/arch)
set (INCLUDE_ASM_DIR ${CMAKE_BINARY_DIR}/include)

# Set lib include directory
set (INCLUDE_LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

# Create architecture dependant links
if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64" OR 
    ${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86")
  execute_process (COMMAND rm -rf ${CMAKE_BINARY_DIR}/include)
  execute_process (COMMAND mkdir -p ${CMAKE_BINARY_DIR}/include)
  execute_process (COMMAND ln -s ${ARCH_DIR}/x86 ${CMAKE_BINARY_DIR}/include/asm)
  execute_process (COMMAND rm -rf ${CMAKE_BINARY_DIR}/arch)
  execute_process (COMMAND mkdir -p ${CMAKE_BINARY_DIR}/arch)
  execute_process (COMMAND ln -s ${ARCH_DIR}/x86 ${CMAKE_BINARY_DIR}/arch/asm)
  
  # Set architecture type in config.h
  if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
    option (__ARCH_X86_64__ "x86_64" ON)
  else ()
    option (__ARCH_X86__ "x86" ON)
  endif ()
else ()
  message (FATAL_ERROR "Unsupported architecture")
endif ()

# Generate config header
configure_file (${INCLUDE_DIR}/config.h.cmake ${INCLUDE_ASM_DIR}/config.h)

add_subdirectory (doc)
add_subdirectory (lib)
add_subdirectory (init)
add_subdirectory (kernel)
#add_subdirectory (servers)

enable_testing ()

