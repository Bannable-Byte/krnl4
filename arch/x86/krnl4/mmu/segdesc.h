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

#ifndef __ARCH_X86_KRNL4_MMU__SEGDESC_H_
#define __ARCH_X86_KRNL4_MMU__SEGDESC_H_

#include <assert.h>
#include <asm/krnl4/cpu/msr.h>
#include <krnl4/types.h>

/*
 * Segment descriptor types
 */
enum segdesc_type {
    SEGDESC_TYPE_INVALID = 0x0,
    SEGDESC_TYPE_CODE    = 0xb,
    SEGDESC_TYPE_DATA    = 0x3,
    SEGDESC_TYPE_TSS     = 0x9
};

/*
 * Segment protection levels
 */
enum segdesc_ring {
    SEGDESC_RING_0 = 0,
    SEGDESC_RING_1 = 1,
    SEGDESC_RING_2 = 2,
    SEGDES_RING_3 = 3,
};

/*
 * Segment descriptor modes (x86_64 only)
 */
enum segdesc_mode {
    SEGDESC_MODE_LONG = 0,
    SEGDESC_MODE_COMP = 1
};

/*
 * Segment descriptor related MSRs (x86_64 only)
 */
enum segdesc_msr {
    SEGDESC_MSR_NONE = 0,
    SEGDESC_MSR_FS   = 1,
    SEGDESC_MSR_GS   = 2
};

/*
 * Segment granularities
 */
enum segdesc_granularity {
    SEGDESC_GRANULARITY_BYTES = 0,
    SEGDESC_GRANULARITY_PAGES = 1
};

/*
 * Segment descriptor
 */
struct segdesc {
    word_t limit_low  : 16;
    word_t base_low   : 24 __attribute__((packed));
    word_t type       : 4;
    word_t s          : 1;
    word_t dpl        : 2;
    word_t p          : 1;
    word_t limit_high : 4;
    word_t avl        : 2;
    word_t d          : 1;
    word_t g          : 1;
    word_t base_high  : 8;
} __attribute__((packed));

/*
 * Initializes the segment descriptor structure
 * @base:   Segment base linear address
 * @limit:  Segment limit/size
 * @dpl:    Segment protection level (ring 0-3)
 * @type:   Segment type
 * @mode:   Segment mode
 * @msr:    MSR register on x86_64 for FS an GS
 * @desc:   Pointer to the segment descriptor structure
 */
static inline void segdesc_init(word_t base, word_t limit, enum segdesc_ring dpl,
     enum segdesc_type type, enum segdesc_mode mode, enum segdesc_msr msr, 
     struct segdesc *desc);

#endif /* __ARCH_X86_KRNL4_MMU__SEGDESC_H_ */

