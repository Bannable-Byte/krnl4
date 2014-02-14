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

#ifndef __ARCH_X86_KRNL4_MMU__LDT_H_
#define __ARCH_X86_KRNL4_MMU__LDT_H_

#include <assert.h>
#include <krnl4/types.h>

/*
 * Local descriptor table register
 */
struct ldtr {
    uint16_t selector;
} __attribute__((packed));


/*
 * Initializes the local descriptor table register structure
 * @selector:   Local descriptor table selector
 * @ldtr:       Pointer to the local descriptor table register structure
 */
static inline void ldtr_init(uint16_t selector, struct ldtr *ldtr) {
    assert(ldtr != nullptr);
    if (ldtr == nullptr)
        return;

    ldtr->selector = selector;
}

/*
 * Loads the local descriptor table register value from the structure
 * @ldtr:   Pointer to the local descriptor table register structure
 */
static inline void ldtr_load(struct ldtr *ldtr) {
    assert(ldtr != nullptr);
    if (ldtr == nullptr)
        return;

    __asm__ __volatile__("lldt %0\n" : /* no output */ : "m"(*ldtr));
}

/*
 * Stores the value from the local descriptor table register to the structure
 * @ldtr:   Pointer to the local descriptor table register structure
 */
static inline void ldtr_store(struct ldtr *ldtr) {
    assert(ldtr != nullptr);
    if (ldtr == nullptr)
        return;

    __asm__ __volatile__("sldt %0\n" : "=m"(*ldtr) : /* no input */);
}

#endif /* __ARCH_X86_KRNL4_MMU_LDT_H_ */

