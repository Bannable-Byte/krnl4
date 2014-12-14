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
 * \file cpu.h
 * \brief Intel x86 architecture cpu structure
 */ 

#ifndef __ARCH_X86_KRNL4_CPU__CPU_H_
#define __ARCH_X86_KRNL4_CPU__CPU_H_

#include <assert.h>
#include <asm/krnl4/mmu/gdt.h>
#include <asm/krnl4/mmu/gdtr.h>
#include <asm/krnl4/mmu/idtr.h>
#include <asm/krnl4/mmu/segdesc.h>
#include <asm/krnl4/mmu/tssdesc.h>
#include <krnl4/types.h>

/*! 
 * \brief CPU initialization error 
 */
#define ECPU    -1

/*! 
 * \brief Architecture dependant cpu structure
 */
struct cpu {
    struct gdt gdt;
    struct gdtr gdtr;
};

/*! 
 * \brief Initializes cpu structure
 * 
 * \param cpu The cpu structure
 * \return The error code 
 */
int cpu_init(struct cpu *cpu); 

/*! 
 * \brief Bootstraps cpu
 *
 * \param cpu The cpu structure
 * \return The error code
 */
int cpu_bootstrap(struct cpu *cpu);

#endif /* __ARCH_X86_KRNL4_CPU__CPU_H */

