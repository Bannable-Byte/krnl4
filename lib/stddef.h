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

#ifndef __LIB__STDDEF_H_
#define __LIB__STDDEF_H_

/*
 * Evaluates the offset in bytes of a member within a structure 
 * @structure:  Structure name
 * @member:     Member name within the structure
 */
#define offsetof(stucture, member) __builtin_offsetof(structure, member)


#endif /* __LIB__STDDEF_H_ */

