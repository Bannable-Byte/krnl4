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
 * \file tssdesc.h
 * \brief Task state segment descriptor for the Intel x86 architecture
 */

#ifndef __ARCH_X86_KRNL4_MMU__TSSDESC_H_
#define __ARCH_X86_KRNL4_MMU__TSSDESC_H_

#include <assert.h>
#include <asm/krnl4/cpu/msr.h>
#include <asm/krnl4/mmu/segdesc.h>
#include <krnl4/types.h>

/*!
 * \brief TSS descriptor types
 */
enum tssdesc_type {
    TSSDESC_TYPE_TSS = 0x9
};

/*!
 * \brief TSS descriptor protection levels
 */
enum tssdesc_ring {
    TSSDESC_RING_0 = 0,
    TSSDESC_RING_1 = 1,
    TSSDESC_RING_2 = 2,
    TSSDESC_RING_3 = 3,
};

/*!
 * \brief TSS descriptor granularities
 */
enum tssdesc_granularity {
    TSSDESC_GRANULARITY_BYTES = 0,
    TSSDESC_GRANULARITY_PAGES = 1
};

#if defined(__ARCH_X86__)

/*!
 * \brief TSS descriptor
 */
typedef segdesc tssdesc;    

#elif defined(__ARCH_X86_64__)

/*!
 * \brief TSS descriptor
 */
struct tssdesc {
    word_t limit_low  : 16;
    word_t base_low   : 24;
    word_t type       : 4;
    word_t s          : 1;
    word_t dpl        : 2;
    word_t p          : 1;
    word_t limit_high : 4;
    word_t avl        : 1;
    word_t res0       : 2;
    word_t g          : 1;
    word_t base_med   : 8;
    word_t base_high  : 32;
    word_t res1       : 8;
    word_t mbz        : 5;
    word_t res2       : 19;
} __attribute__((packed));

#else
#error Unknown architecture
#endif

/*!
 * \brief Initializes the TSS descriptor structure
 * 
 * \param base TSS base linear address
 * \param limit TSS limit/size
 * \param desc TSS desc struct
 */
void tssdesc_init(word_t base, word_t limit, struct tssdesc *desc);

#endif /* __ARCH_X86_KRNL4_MMU__TSSDESC_H_ */

