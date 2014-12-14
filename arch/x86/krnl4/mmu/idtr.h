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
 * \file idtr.h
 * \brief Interrupt descriptor table register for the Intel x86 architecture
 */

#ifndef __ARCH_X86_KRNL4_MMU__IDTR_H_
#define __ARCH_X86_KRNL4_MMU__IDTR_H_

#include <assert.h>
#include <krnl4/types.h>

/*!
 * \brief Interrupts descriptor table register
 */
struct idtr {
    uint16_t size;
    word_t addr;
} __attribute__((packed));


/*!
 * \brief Initializes an interrupts descriptor table register structure
 *
 * \param addr Linear addres of the table
 * \param size The size of the table subtracted by 1
 * \param idtr Pointer to the interrupts descriptor table register structure
 */
static inline void idtr_init(word_t addr, uint16_t size, struct idtr *idtr) {
    assert(idtr != nullptr);
    if (idtr == nullptr)
        return;

    idtr->size = size;
    idtr->addr = addr;
}

/*!
 * \brief Loads the interrupts descriptor table register structure into the register
 * 
 * \param idtr Pointer to the interupts descriptor table register structure
 */
static inline void idtr_load(struct idtr *idtr) {
    assert(idtr != nullptr);
    if (idtr == nullptr)
        return;

    __asm__ __volatile__("lidt %0\n" : /* no output */ : "m"(*idtr));
}

/*!
 * \brief Stores the value from the interrupts descriptor table register to the structure
 * 
 * \param idtr Pointer to the interrupts descriptor table register structure
 */
static inline void idtr_store(struct idtr *idtr) {
    assert(idtr != nullptr);
    if (idtr == nullptr)
        return;

    __asm__ __volatile__("sidt %0\n" : "=m"(*idtr) : /* no input */);
}

#endif /* __ARCH_X86_KRNL4_MMU__IDTR_H_ */

