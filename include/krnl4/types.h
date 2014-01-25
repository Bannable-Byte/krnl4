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

#ifndef _TYPES_H
#define _TYPES_H

#include <asm/krnl4/types.h>

/* Define bool type */
typedef _Bool bool;

#define true 1
#define false 0

/* Signal that all the definitions are present */
#define __bool_true_false_are_defined 1

/* Define nullptr */
#define nullptr ((addr_t)0)

/* Signal that all the definitions are present */
#define __nullptr_is_defined 1

#endif /* _TYPES_H */
