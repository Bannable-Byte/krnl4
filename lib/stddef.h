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
 * \file stddef.h
 * \brief Standard definitions for the kernel library
 */

#ifndef __LIB__STDDEF_H_
#define __LIB__STDDEF_H_

/*!
 * \brief Evaluates the offset in bytes of a member within a structure 
 *
 * \param stucture Structure name
 * \param member Member name within the structure
 */
#define offsetof(stucture, member) __builtin_offsetof(structure, member)

/*!
 * \brief Casts a member of a structure out to the containing structure
 *
 * \param ptr Pointer to the member
 * \param type The type of the container struct this is embedded in
 * \param member The name of the member within the struct
 */
#define container_of(ptr, type, member) \
    ({ \
        const __typeof__(((type *)0)->member) *__mptr = (ptr); \
        (type *)((char *)__mptr - offsetof(type, member)); \
    })

#endif /* __LIB__STDDEF_H_ */

