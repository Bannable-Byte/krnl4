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
 * \file gdt.h
 * \brief Global descriptor table (GDT) for the Intel x86 architecture
 */

#ifndef __ARCH_X86_KRNL4_CPU__GDT_H_
#define __ARCH_X86_KRNL4_CPU__GDT_H_

#include <assert.h>
#include <asm/krnl4/mmu/segdesc.h>
#include <asm/krnl4/mmu/tssdesc.h>
#include <krnl4/types.h>

/*!
 * \brief GDT initialization error 
 */
#define EGDT    -1

#define GDT_NULL_BASE       0x0 /*!< \brief NULL descriptor */
#define GDT_KRNL_CS_BASE    0x0 /*!< \brief Kernel code segment base */
#define GDT_KRNL_DS_BASE    0x0 /*!< \brief Kernel data segment base */
#define GDT_USR_CS_BASE     0x0 /*!< \brief User space code segment base */
#define GDT_USR_DS_BASE     0x0 /*!< \brief User space data segment base */
#define GDT_TSS_BASE        0x0 /*!< \brief Task state segment base */

/* GDT segment limits */
#if defined(__ARCH_X86__)

#define GDT_NULL_LIMIT      0x0          /*!< \brief NULL descriptor */
#define GDT_KRNL_CS_LIMIT   0xffffffffUL /*!< \brief Kernel code segment limit */
#define GDT_KRNL_DS_LIMIT   0xffffffffUL /*!< \brief Kernel data segment limit */
#define GDT_USR_CS_LIMIT    0xffffffffUL /*!< \brief User space code segment limit */
#define GDT_USR_DS_LIMIT    0xffffffffUL /*!< \brief User space data segment limit */
#define GDT_TSS_LIMIT       0xffffffffUL /*!< \brief Task state segment limit */

#elif defined(__ARCH_X86_64__)

#define GDT_NULL_LIMIT      0x0                  /*!< \brief NULL descriptor */
#define GDT_KRNL_CS_LIMIT   0xffffffffffffffffUL /*!< \brief Kernel code segment limit */
#define GDT_KRNL_DS_LIMIT   0xffffffffffffffffUL /*!< \brief Kernel data segment limit */
#define GDT_USR_CS_LIMIT    0xffffffffffffffffUL /*!< \brief User space code segment limit */
#define GDT_USR_DS_LIMIT    0xffffffffffffffffUL /*!< \brief User space data segment limit */
#define GDT_TSS_LIMIT       0xffffffffffffffffUL /*!< \brief Task state segment limit */

#else
#error Unknown architecture
#endif

/*!
 * \brief Global descriptor table 
 */
struct gdt {
    struct segdesc null;            /*!< \brief NULL segment descriptor */
    struct segdesc krnl_cs;         /*!< \brief Kernel code segment descriptor */
    struct segdesc krnl_ds;         /*!< \brief Kernel data segment descriptor */
    struct segdesc usr_cs;          /*!< \brief User space code segment descriptor */
#if defined(__ARCH_X86_64__)
    /* 32-bit code compatibility */
    struct segdesc usr_cs_comp;     /*!< \brief Compatibility code segment descriptor on 64bit */
#endif
    struct segdesc usr_ds;          /*!< \brief User space data segement descriptor */
    struct tssdesc tss;             /*!< \brief Task state segment descriptor */
} __attribute__((packed));

/*!
 * \brief Initializes global descriptor table structure
 *
 * \param gdt Global descriptor table structure
 * \return Error code
 */
int gdt_init(struct gdt *gdt);

#endif /* __ARCH_X86_KRNL4_CPU__GDT_H_ */

