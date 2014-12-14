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
 * \file arch/x86/krnl4/cpu/irq.h
 * \brief IRQ routines for the Intel x86 architecture
 */ 

#ifndef __ARCH_X86_KRNL4_CPU__IRQ_H_
#define __ARCH_X86_KRNL4_CPU__IRQ_H_

#include <assert.h>
#include <krnl4/types.h>

/*!
 * \brief Native IRQ disable
 */
static inline void irq_disable(void) {
    __asm__ volatile("cli": : :"memory");
}

/*!
 * \brief Native IRQ enable
 */
static inline void irq_enable(void) {
    __asm__ volatile("sti": : :"memory");
}


#endif /* __ARCH_X86_KRNL4_CPU__IRQ_H */

