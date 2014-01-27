#
#  This file is part of the krnl4
#  Copyright (C) 2014  Aleksandar Dezelin <dezelin@gmail.com>
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

project (krnl4 C)
cmake_minimum_required (VERSION 2.8)

set (APPLICATION_NAME "krnl4")
set (APPLICATION_CODENAME "${PROJECT_NAME}")
set (APPLICATION_COPYRIGHT_YEARS "2014")
set (APPLICATION_VERSION_MAJOR 0)
set (APPLICATION_VERSION_MINOR 0)
set (APPLICATION_VERSION_PATCH 1)
set (APPLICATION_VERSION_TYPE SNAPSHOT)
set (APPLICATION_VERSION_STRING
  "${APPLICATION_VERSION_MAJOR}.
   ${APPLICATION_VERSION_MINOR}.
   ${APPLICATION_VERSION_PATCH}-
   ${APPLICATION_VERSION_TYPE}"
)

set (project_BIN ${PROJECT_NAME})

# Enable assembler
enable_language (ASM)
if (NOT CMAKE_ASM_COMPILER_WORKS)
  message (FATAL_ERROR "Can't find the assembler")
endif ()

set (project_SOURCES
  ${ARCH_ASM_DIR}/asm/boot/mbh.S
)

# Add source files
set (project_SOURCES ${project_SOURCES}
    krnl4.c
)

# Append root include and build/include directories
include_directories (${INCLUDE_DIR})
include_directories (${INCLUDE_ASM_DIR})

# Set kernel linking flags
set (CMAKE_EXE_LINKER_FLAGS
  "-Wl,--build-id=none -Wl,-N -Wl,-T ${CMAKE_CURRENT_SOURCE_DIR}/krnl4.lds" 
)

# Set kernel C compilation flags
set (CMAKE_C_FLAGS "-Wall -pedantic -ffreestanding -fno-builtin -nostdinc -nostdlib -std=c99")

# Kernel ELF target
add_executable (${project_BIN} ${project_SOURCES})

# Add kernel dependencies
target_link_libraries (${project_BIN} init)

install (TARGETS ${project_BIN} DESTINATION bin)

enable_testing ()

