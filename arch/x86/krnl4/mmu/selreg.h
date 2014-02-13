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

#ifndef __ARCH_X86_KRNL4_MMU__SELREG_H_
#define __ARCH_X86_KRNL4_MMU__SELREG_H_

#include <assert.h>
#include <krnl4/types.h>

/*
 * Selector register
 */
struct selector_register {
    uint16_t selector;
} __attribute__((packed));


/*
 * Initializes the selector register structure
 * @selector:   Selector value
 * @sel:        Pointer to the selector register structure
 */
static inline void selector_register_init(uint16_t selector, 
    struct selector_register *sel) {
    assert(sel != nullptr);
    if (sel == nullptr)
        return;

    sel->selector = selector;
}

#endif /* __ARCH_X86_KRNL4_MMU__SELREG_H_ */

