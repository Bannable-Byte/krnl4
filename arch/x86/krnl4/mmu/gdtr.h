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
 * \file gdtr.h
 * \brief Global descriptor table register for the Intel x86 architecture
 */

#ifndef __ARCH_X86_KRNL4_MMU__GDTR_H_
#define __ARCH_X86_KRNL4_MMU__GDTR_H_

#include <assert.h>
#include <krnl4/types.h>

/*!
 * \brief Global descriptor table register
 */
struct gdtr {
    uint16_t size;
    word_t addr;
} __attribute__((packed));


/*!
 * \brief Initializes the global descriptor table register structure
 *
 * \param addr Linear address of the table
 * \param size Size of the table subtracted by 1
 * \param gdtr Pointer to a gdtr structure to be initialized
 */
static inline void gdtr_init(word_t addr, uint16_t size, struct gdtr *gdtr) {
    assert(gdtr != nullptr);
    if (gdtr == nullptr)
        return;

    gdtr->size = size;
    gdtr->addr = addr;
}

/*!
 * \brief Loads the global descriptor table from the structure into the register
 *
 * \param gdtr Pointer to the global descriptor table register structure
 */
static inline void gdtr_load(const struct gdtr *gdtr) {
    assert(gdtr != nullptr);
    if (gdtr == nullptr)
        return;

    __asm__ __volatile__("lgdt %0\n" : /* no output */ : "m"(*gdtr)); 
}

/*!
 * \brief Stores the global descriptor table register value to the structure
 *
 * \param gdtr Pointer to the global descriptor table register structure
 */
static inline void gdtr_store(struct gdtr *gdtr) {
    assert(gdtr != nullptr);
    if (gdtr == nullptr)
        return;

    __asm__ __volatile__("sgdt %0\n" : "=m"(*gdtr) : /* no input */);
}

#endif /* __ARCH_X86_KRNL4_MMU__GDTR_H_ */

