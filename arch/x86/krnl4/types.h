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
 * \file arch/x86/krnl4/types.h
 * \brief Arhitecture dependent typedefs for the Intel x86 architecture
 */

#ifndef __ARCH_X86_KRNL4__TYPES_H_
#define __ARCH_X86_KRNL4__TYPES_H_

#include <config.h>

/*!
 * \brief No error 
 */
#define ENO 0

#if defined(__ARCH_X86__)

/*!
 * \brief size_t type
 */
#define SIZE_T unsigned int

/*!
 * \brief Unsigned integer, eight times as wide as a QI mode integer, 64 bits 
 */
typedef unsigned int uint64_t __attribute__((mode(DI)));

/*!
 * \brief Unsigned integer, 32 bits
 */
typedef unsigned int uint32_t;

/*!
 * \brief Unsigned integer, 16 bits
 */
typedef unsigned short uint16_t;

/*!
 * \brief Unsigned integer, 8 bits
 */
typedef unsigned char uint8_t;

/*!
 * \brief Signed integer, eight times as wide as a QI mode integer, 64 bits 
 */
typedef signed int int64_t __attribute__((mode(DI)));

/*!
 * \brief Signed integer, 32 bits
 */
typedef signed int int32_t;

/*!
 * \brief Signed integer, 16 bits
 */
typedef signed short int16_t;

/*!
 * \brief Signed integer, 8 bits
 */
typedef signed char int8_t;

/*!
 * \brief  Machine word wide unsigned integer 
 */
typedef uint32_t word_t;

#elif defined(__ARCH_X86_64__)

/*!
 * \brief size_t type
 */
#define SIZE_T long unsigned int

/*!
 * \brief Unsigned integer, 64 bits
 */
typedef unsigned long uint64_t;

/*!
 * \brief Unsigned integer, 32 bits
 */
typedef unsigned int uint32_t;

/*!
 * \brief Unsigned integer, 16 bits
 */
typedef unsigned short uint16_t;

/*!
 * \brief Unsigned integer, 8 bits
 */
typedef unsigned char uint8_t;

/*!
 * \brief Signed integer, 64 bits
 */
typedef signed long int64_t;

/*!
 * \brief Signed integer, 32 bits
 */
typedef signed int int32_t;

/*!
 * \brief Signed integer, 16 bits
 */
typedef signed short int16_t;

/*!
 * \brief Signed integer, 8 bits
 */
typedef signed char int8_t;

/*!
 * \brief Machine word wide unsigned integer 
 */
typedef uint64_t word_t;

#else
#error "Unknown x86 architecture"
#endif

/*!
 * \brief Size type 
 */
typedef SIZE_T size_t;

/*!
 * \brief Pointer type 
 */
typedef void* addr_t;

/*!
 * \brief Integer address type 
 */
typedef word_t addr_word_t;

/*!
 * \brief Physical address type 
 */
typedef void* paddr_t;

#endif /* __ARCH_X86_KRNL4__TYPES_H_ */

