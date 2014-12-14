/*
 * This file is part of the krnl4
 * Copyright (C) 2014 Aleksandar Dezelin <dezelin@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 * \file panic.h
 * \brief Kernel panic support
 */

#ifndef __INCLUDE_KRNL4__PANIC_H_
#define __INCLUDE_KRNL4__PANIC_H_ 

/*!
 * \brief Causes kernel to panic and to dump registers and stacktrace to the console.
 * 
 * \param msg Message to be included in the dump.
 */
void panic(char *msg);

#endif /*__INCLUDE_KRNL4__PANIC_H_ */

