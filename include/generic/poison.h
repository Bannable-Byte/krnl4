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
 * \file poison.h
 * \brief Pointer poison values
 */

#ifndef __INCLUDE_GENERIC__POISON_H_
#define __INCLUDE_GENERIC__POISON_H_

#include <krnl4/types.h>

/*!
 * \brief List pointer poison value 
 */
#define LIST_POISON_PTR (addr_t)0xdead000000000000UL

#endif /* __INCLUDE_GENERIC__POISON_H_ */

