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

#include <assert.h>
#include <krnl4/types.h>

#include "segdesc.h"
#include "tssdesc.h"

void tssdesc_init(word_t base, word_t limit, struct tssdesc *desc) {
    assert(desc != nullptr);
    if (desc == nullptr)
        return;

#if defined(__ARCH_X86__)
    
    desc->limit_low = limit & 0xFFFF;
    desc->limit_high = limit >> 16;
    desc->base_low = base & 0xFFFFFF;
    desc->base_high = (base >> 24) & 0xFF;
    desc->type = TSSDESC_TYPE_TSS;
    desc->dpl = TSSDESC_RING_0;
    desc->p = 1;
    desc->g = TSSDESC_GRANULARITY_BYTES;
    desc->d = 0;
    desc->s = 1;
    desc->avl = 0;

#elif defined(__ARCH_X86_64__)

    desc->base_low = base & 0xFFFFFF;
    desc->base_med = (base >> 24) & 0xFF;
    desc->base_high = (base >> 32) & 0xFFFFFFFF;
    if (limit > (1 << 20)) {
        desc->limit_low = (limit >> 12) & 0xFFFF;
        desc->limit_high = (limit >> 28) & 0xF;
        desc->g = TSSDESC_GRANULARITY_PAGES;
    } else {
        desc->limit_low =  limit & 0xFFFF;
        desc->limit_high = (limit >> 16) & 0xFF;
        desc->g = TSSDESC_GRANULARITY_BYTES;
    }
    
    desc->type = TSSDESC_TYPE_TSS;
    desc->s = 1;
    desc->dpl = TSSDESC_RING_0;
    desc->p = 1;
    desc->avl = 0;
    desc->mbz = 0;
    desc->res0 = 0;

#else
#error Unknown architecture
#endif

}

