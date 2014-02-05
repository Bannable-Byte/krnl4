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

#ifndef __INCLUDE__GENERIC__MACROS_H_
#define __INCLUDE__GENERIC__MACROS_H_

#include <stddef.h>
#include <krnl4/types.h>

/* 
 * Spins the cpu eternaly 
 * @cpu:    CPU index
 */
#define spin_forever(cpu) do {} while(true)

/* Converts macro argument to string 
 * @x:  x -> "x"
 */
#define STRINGIFY(x) #x

/* Expands macro argument value to string 
 * @x:  x -> x() -> "result"
 */
#define STRINGIFY_EXPAND(x) STRINGIFY(x)

#endif /* __INCLUDE__GENERIC__MACROS_H_ */

