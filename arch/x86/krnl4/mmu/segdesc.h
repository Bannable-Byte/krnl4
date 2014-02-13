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
enum segment_descriptor_type {
    SEGMENT_DESCRIPTOR_TYPE_INVALID = 0x0,
    SEGMENT_DESCRIPTOR_TYPE_CODE    = 0xb,
    SEGMENT_DESCRIPTOR_TYPE_DATA    = 0x3,
    SEGMENT_DESCRIPTOR_TYPE_TSS     = 0x9
};

/*
 * Segment protection levels
 */
enum segment_descriptor_ring {
    SEGMENT_DESCRIPTOR_RING_0 = 0,
    SEGMENT_DESCRIPTOR_RING_1 = 1,
    SEGMENT_DESCRIPTOR_RING_2 = 2,
    SEGMENT_DESCRIPTOR_RING_3 = 3,
};

/*
 * Segment descriptor modes (x86_64 only)
 */
enum segment_descriptor_mode {
    SEGMENT_DESCRIPTOR_MODE_LONG = 0,
    SEGMENT_DESCRIPTOR_MODE_COMP = 1
};

/*
 * Segment descriptor related MSRs (x86_64 only)
 */
enum segment_descriptor_msr {
    SEGMENT_DESCRIPTOR_MSR_NONE = 0,
    SEGMENT_DESCRIPTOR_MSR_FS   = 1,
    SEGMENT_DESCRIPTOR_MSR_GS   = 2
};

/*
 * Segment granularities
 */
enum segment_granularity {
    SEGMENT_GRANULARITY_BYTES = 0,
    SEGMENT_GRANULARITY_PAGES = 1
};

/*
 * Segment descriptor
 */
struct segment_descriptor {
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
static inline void segment_descriptor_init(word_t base, word_t limit,
    enum segment_descriptor_ring dpl, enum segment_descriptor_type type, 
    enum segment_descriptor_mode mode, enum segment_descriptor_msr msr, 
    struct segment_descriptor *desc) {
    assert(desc != nullptr);
    if (desc == nullptr)
        return;

    if (msr != SEGMENT_DESCRIPTOR_MSR_NONE && (base >> 32)) {
        uint32_t reg = (msr == SEGMENT_DESCRIPTOR_MSR_FS) 
            ? IA32_FS_BASE : IA32_GS_BASE;
        write_msr(base, reg);  
    }

    if (limit > (1 << 20)) {
        desc->limit_low = (limit >> 12) & 0xffff;
        desc->limit_high = (limit >> 28) & 0xf;
        desc->g = SEGMENT_GRANULARITY_PAGES;
    } else {
        desc->limit_low = limit & 0xffff;
        desc->limit_high = limit >> 16;
        desc->g = SEGMENT_GRANULARITY_BYTES;
    }

    desc->base_low = base & 0xffffff;
    desc->base_high = (base >> 24) & 0xff;
    desc->type = type;
    desc->avl = mode;
    desc->dpl = dpl;

    desc->d = (type == SEGMENT_DESCRIPTOR_TYPE_CODE)
        ? mode : SEGMENT_DESCRIPTOR_MODE_COMP;

    desc->p = 1;
    desc->s = 1;
}

#endif /* __ARCH_X86_KRNL4_MMU__SEGDESC_H_ */

