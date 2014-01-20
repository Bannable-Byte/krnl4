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

project (krnl4)
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

#add_subdirectory (servers)

set (project_BIN ${PROJECT_NAME})

set (project_SOURCES
    placeholder.c
)

add_executable (${project_BIN} ${project_SOURCES})

install (TARGETS ${project_BIN} DESTINATION bin)

enable_testing ()

