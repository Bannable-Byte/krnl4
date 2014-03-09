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
#include <asm/krnl4/mmu/segdesc.h>
#include <asm/krnl4/mmu/tssdesc.h>
#include <krnl4/types.h>

#include "gdt.h"

int gdt_init(struct gdt *gdt) {
    assert(gdt != nullptr);
    if (gdt == nullptr)
        return EGDT;

#if defined(__ARCH_X86__)
    enum segdesc_mode codeseg_mode = SEGDESC_MODE_COMP; 
#elif defined(__ARCH_X86_64__)
    enum segdesc_mode codeseg_mode = SEGDESC_MODE_LONG; 
#else
#error Unknown architecture
#endif

    enum segdesc_mode dataseg_mode = SEGDESC_MODE_COMP;
    
    /* NULL descriptor */
    segdesc_init(GDT_NULL_BASE, GDT_NULL_LIMIT, SEGDESC_RING_0, 
        SEGDESC_TYPE_INVALID, codeseg_mode, SEGDESC_MSR_NONE, &gdt->null);

    /* Kernel CS */
    segdesc_init(GDT_KRNL_CS_BASE, GDT_KRNL_CS_LIMIT, SEGDESC_RING_0,
        SEGDESC_TYPE_CODE, codeseg_mode, SEGDESC_MSR_NONE, &gdt->krnl_cs);

    /* Kernel DS */
    segdesc_init(GDT_KRNL_DS_BASE, GDT_KRNL_DS_LIMIT, SEGDESC_RING_0,
        SEGDESC_TYPE_DATA, dataseg_mode, SEGDESC_MSR_NONE, &gdt->krnl_ds);
    
    /* User space CS */
    segdesc_init(GDT_USR_CS_BASE, GDT_USR_CS_LIMIT, SEGDESC_RING_3,
        SEGDESC_TYPE_CODE, codeseg_mode, SEGDESC_MSR_NONE, &gdt->usr_cs);
    
#if defined(__ARCH_X86_64__)
    /* User space CS 32-bit compatibility (only x86_64) */
    segdesc_init(GDT_USR_CS_BASE, GDT_USR_CS_LIMIT, SEGDESC_RING_3,
        SEGDESC_TYPE_CODE, SEGDESC_MODE_COMP, SEGDESC_MSR_NONE, &gdt->usr_cs_comp);
#endif

    /* User space DS */
    segdesc_init(GDT_USR_DS_BASE, GDT_USR_DS_LIMIT, SEGDESC_RING_3,
        SEGDESC_TYPE_DATA, dataseg_mode, SEGDESC_MSR_NONE, &gdt->usr_ds);

    /* TSS descriptor */
    tssdesc_init(GDT_TSS_BASE, GDT_TSS_LIMIT, &gdt->tss);
    
    return ENO;
}

