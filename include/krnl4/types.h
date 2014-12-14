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
 * \file include/krnl4/types.h
 * \brief Generic kernel typedefs
 */

#ifndef __INCLUDE_KRNL4__TYPES_H_
#define __INCLUDE_KRNL4__TYPES_H_

#include <asm/krnl4/types.h>

/*!
 * \brief Defines bool type 
 */
typedef _Bool bool;

/*!
 * \brief True boolean value
 */
#define true 1

/*!
 * \brief False boolean value
 */
#define false 0

/*!
 * \brief Signals that all the definitions are present 
 */
#define __bool_true_false_are_defined 1

/*! 
 * \brief Defines nullptr 
 */
#define nullptr ((addr_t)0)

/*! 
 * \brief Signals that all the definitions are present 
 */
#define __nullptr_is_defined 1

#endif /* __INCLUDE_KRNL4__TYPES_H_ */

