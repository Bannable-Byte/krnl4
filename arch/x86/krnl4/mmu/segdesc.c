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

#include "segdesc.h"


void segdesc_init(word_t base, word_t limit, enum segdesc_ring dpl, 
    enum segdesc_type type, enum segdesc_mode mode, enum segdesc_msr msr, 
    struct segdesc *desc) {
    assert(desc != nullptr);
    if (desc == nullptr)
        return;

    if (msr != SEGDESC_MSR_NONE && (base >> 32)) {
        uint32_t reg = (msr == SEGDESC_MSR_FS) 
            ? IA32_FS_BASE : IA32_GS_BASE;
        write_msr(base, reg);  
    }

    if (limit > (1 << 20)) {
        desc->limit_low = (limit >> 12) & 0xffff;
        desc->limit_high = (limit >> 28) & 0xf;
        desc->g = SEGDESC_GRANULARITY_PAGES;
    } else {
        desc->limit_low = limit & 0xffff;
        desc->limit_high = limit >> 16;
        desc->g = SEGDESC_GRANULARITY_BYTES;
    }

    desc->base_low = base & 0xffffff;
    desc->base_high = (base >> 24) & 0xff;
    desc->type = type;
    desc->avl = mode;
    desc->dpl = dpl;
    desc->d = (type == SEGDESC_TYPE_CODE) ? mode : SEGDESC_MODE_COMP;
    desc->p = 1;
    desc->s = 1;
}

