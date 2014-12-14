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
 * \file macros.h
 * \brief Generic macros needed in different places
 */

#ifndef __INCLUDE__GENERIC__MACROS_H_
#define __INCLUDE__GENERIC__MACROS_H_

#include <stddef.h>
#include <krnl4/types.h>

/*!
 * \brief Spins the cpu eternaly 
 * \param cpu Index of the cpu
 */
#define spin_forever(cpu) do {} while(true)

/*!
 * \brief Converts macro argument to string 
 * \param x x -> "x"
 */
#define STRINGIFY(x) #x

/*!
 * \brief Expands macro argument value to string 
 * \param x x -> x() -> "result"
 */
#define STRINGIFY_EXPAND(x) STRINGIFY(x)

#endif /* __INCLUDE__GENERIC__MACROS_H_ */

