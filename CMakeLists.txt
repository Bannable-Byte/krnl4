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

if (CMAKE_BINARY_DIR STREQUAL ${CMAKE_SOURCE_DIR})
  message(FATAL_ERROR "type: git clean -df && mkdir build && cd build && cmake .. && make")
endif()

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_VERBOSE_MAKEFILE 1)
else ()
  set(CMAKE_VERBOSE_MAKEFILE 0)
endif ()

add_subdirectory (kernel)
#add_subdirectory (servers)

enable_testing ()

