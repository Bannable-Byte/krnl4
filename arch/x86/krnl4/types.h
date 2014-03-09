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

#ifndef __ARCH_X86_KRNL4__TYPES_H_
#define __ARCH_X86_KRNL4__TYPES_H_

#include <config.h>

/* No error */
#define ENO 0

#if defined(__ARCH_X86__)

#define SIZE_T unsigned int

/* An unsigned integer, eight times as wide as a QI mode integer, 64 bits */
typedef unsigned int uint64_t __attribute__((mode(DI)));
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

/* A signed integer, eight times as wide as a QI mode integer, 64 bits */
typedef signed int int64_t __attribute__((mode(DI)));
typedef signed int int32_t;
typedef signed short int16_t;
typedef signed char int8_t;

/* Machine word wide unsigned integer */
typedef uint32_t word_t;

#elif defined(__ARCH_X86_64__)

#define SIZE_T long unsigned int

typedef unsigned long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

typedef signed long int64_t;
typedef signed int int32_t;
typedef signed short int16_t;
typedef signed char int8_t;

/* Machine word wide unsigned integer */
typedef uint64_t word_t;

#else
#error "Unknown x86 architecture"
#endif

/* Size type */
typedef SIZE_T size_t;

/* Pointer type */
typedef void* addr_t;

/* Integer address type */
typedef word_t addr_word_t;

/* Physical address type */
typedef void* paddr_t;

#endif /* __ARCH_X86_KRNL4__TYPES_H_ */

