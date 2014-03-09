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

#ifndef __ARCH_X86_KRNL4_CPU__CPU_H_
#define __ARCH_X86_KRNL4_CPU__CPU_H_

#include <assert.h>
#include <asm/krnl4/mmu/gdt.h>
#include <asm/krnl4/mmu/idt.h>
#include <asm/krnl4/mmu/segdesc.h>
#include <krnl4/types.h>

/* CPU error */
#define ECPU    -1

/* GDT size */
#define CPU_GDT_LENGTH  6

/* IDT size */
#define CPU_IDT_LENGTH  6

/*
 * Architecture dependant CPU structure
 */
struct cpu {
    struct segdesc gdt[CPU_GDT_LENGTH];
    struct segdesc idt[CPU_IDT_LENGTH];
    struct gdtr gdtr;
    struct idtr  idtr;
};

/*
 * Initializes CPU structure
 * @cpu         A CPU structure
 * @returns     Negative value on error
 */
int cpu_init(struct cpu *cpu); 

/*
 * Starts CPU
 * @cpu         A CPU structure
 * @returns     Negative value on error
 */
int cpu_bootstrap(struct cpu *cpu);

#endif /* __ARCH_X86_KRNL4_CPU__CPU_H */

