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
 * \file tr.h
 * \brief Task register structure
 */

#ifndef __ARCH_X86_KRNL4_MMU__TR_H_
#define __ARCH_X86_KRNL4_MMU__TR_H_

#include <assert.h>
#include <krnl4/types.h>

/*!
 * \brief Task register structure
 */
struct tr {
    uint16_t selector;
} __attribute__((packed));


/*!
 * \brief Initializes the task register structure
 * 
 * \param selector Task register selector
 * \param tr Pointer to the task register structure
 */
static inline void tr_init(uint16_t selector, struct tr *tr) {
    assert(tr != nullptr);
    if (tr == nullptr)
        return;

    tr->selector = selector;
}

/*!
 * \brief Loads the task register structure value into the register
 * 
 * \param tr Pointer to the task register structure
 */
static inline void tr_load(struct tr *tr) {
    assert(tr != nullptr);
    if (tr == nullptr)
        return;

    __asm__ __volatile__("ltr %0\n" : /* no output */ : "m"(*tr));
}

/*!
 * \brief Stores the task register value to the structure
 * 
 * \param tr Pointer to the task register structure
 */
static inline void tr_store(struct tr *tr) {
    assert(tr != nullptr);
    if (tr == nullptr)
        return;

    __asm__ __volatile__("str %0\n" : "=m"(*tr) : /* no input */);
}

#endif /* __ARCH_X86_KRNL4_MMU__TR_H_ */

