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

#ifndef __ARCH_X86_KRNL4_CPU__GDT_H_
#define __ARCH_X86_KRNL4_CPU__GDT_H_

#include <assert.h>
#include <asm/krnl4/mmu/segdesc.h>
#include <asm/krnl4/mmu/tssdesc.h>
#include <krnl4/types.h>

/* GDT initialization error */
#define EGDT    -1

/* GDT segment bases */
#define GDT_NULL_BASE       0x0
#define GDT_KRNL_CS_BASE    0x0
#define GDT_KRNL_DS_BASE    0x0
#define GDT_USR_CS_BASE     0x0
#define GDT_USR_DS_BASE     0x0
#define GDT_TSS_BASE        0x0

/* GDT segment limits */
#if defined(__ARCH_X86__)

#define GDT_NULL_LIMIT      0x0
#define GDT_KRNL_CS_LIMIT   0xffffffffUL
#define GDT_KRNL_DS_LIMIT   0xffffffffUL
#define GDT_USR_CS_LIMIT    0xffffffffUL
#define GDT_USR_DS_LIMIT    0xffffffffUL
#define GDT_TSS_LIMIT       0xffffffffUL

#elif defined(__ARCH_X86_64__)

#define GDT_NULL_LIMIT      0x0
#define GDT_KRNL_CS_LIMIT   0xffffffffffffffffUL
#define GDT_KRNL_DS_LIMIT   0xffffffffffffffffUL
#define GDT_USR_CS_LIMIT    0xffffffffffffffffUL
#define GDT_USR_DS_LIMIT    0xffffffffffffffffUL
#define GDT_TSS_LIMIT       0xffffffffffffffffUL

#else
#error Unknown architecture
#endif

struct gdt {
    struct segdesc null;
    struct segdesc krnl_cs;
    struct segdesc krnl_ds;
    struct segdesc usr_cs;
#if defined(__ARCH_X86_64__)
    /* 32-bit code compatibility */
    struct segdesc usr_cs_comp;
#endif
    struct segdesc usr_ds;
    struct tssdesc tss;
} __attribute__((packed));

/*
 * Initializes Global descriptor table structure
 * @gdt     Global descriptor table structure
 * @return  Error code
 */
int gdt_init(struct gdt *gdt);

#endif /* __ARCH_X86_KRNL4_CPU__GDT_H_ */

