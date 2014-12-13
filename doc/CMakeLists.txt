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

project (doc NONE)
cmake_minimum_required (VERSION 2.8)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if (BUILD_DOCUMENTATION)
    if (NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set (doxyfile_in_kernel ${CMAKE_CURRENT_SOURCE_DIR}/../kernel/Doxyfile.in)
    set (doxyfile_kernel ${CMAKE_CURRENT_BINARY_DIR}/../kernel/Doxyfile)

    #set (doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    #set (doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file (${doxyfile_in_kernel} ${doxyfile_kernel} @ONLY)

    add_custom_target (doc_kernel
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_kernel}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../kernel/
        COMMENT "Generating kernel API documentation with Doxygen"
        VERBATIM)

    add_custom_target (doc
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

    add_dependencies (doc doc_kernel)

    install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../kernel/html DESTINATION share/doc/kernel)
endif ()

