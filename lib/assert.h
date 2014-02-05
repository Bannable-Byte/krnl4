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

#ifndef __LIB__ASSERT_H_
#define __LIB__ASSERT_H_

#include <config.h>

#if defined(__DEBUG__)

#include <generic/macros.h>
#include <krnl4/types.h>
#include <krnl4/panic.h>

/*
 * Panics in DEBUG build if x isn't true.
 * @x:  The expression to test if it's true or not.
 */
#define assert(x) \
    while(!(x)) { panic(STRINGIFY(x)); }

#else

#define assert(x)

#endif /* __DEBUG__ */

#endif /* __LIB__ASSERT_H_ */

