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
 * \file atomic32.h
 * \brief Intel x86 architecture implementation of 32 bits atomic
 */ 

#ifndef __ARCH_X86_KRNL4_SYNC__ATOMIC32_H_
#define __ARCH_X86_KRNL4_SYNC__ATOMIC32_H_

#include <assert.h>
#include <krnl4/types.h>

typedef struct {
    int v;
} atomic32_t;

#define ATOMIC32_INIT(x) { (x) }

/*!
 * \brief Reads the value atomically 
 *
 * \param a Pointer to atomic
 * \return Value
 */
static inline int atomic32_read(const atomic32_t *a) {
    /* Cast to volatile int* before returning */
    return *(volatile __typeof__(a->v) *)&(a->v);
}

/*!
 * \brief Sets the value atomically
 *
 * \param v Value
 * \param a Pointer to atomic
 */
static inline void atomic32_set(int v, atomic32_t *a) {
    a->v = v;
}

/*! 
 * \brief Adds the value v atomically
 *
 * \param v Value
 * \param a Pointer to atomic
 */
static inline void atomic32_add(int v, atomic32_t *a) {
    __asm__ volatile("lock; addl %1, %0" : "+m"(a->v) : "ir"(v));
}

/*! 
 * \brief Substracts the value v atomically
 *
 * \param v Value
 * \param a Pointer to atomic
 */
static inline void atomic32_sub(int v, atomic32_t *a) {
    __asm__ volatile("lock; subl %1, %0" : "+m"(a->v) : "ir"(v));
}

/*! 
 * \brief Increments atomically
 *
 * \param a Pointer to atomic
 */
static inline void atomic32_inc(atomic32_t *a) {
    __asm__ volatile("lock; incl %0" : "+m"(a->v));
}

/*! 
 * \brief Decrements atomically
 *
 * \param a Pointer to atomic
 */
static inline void atomic32_dec(atomic32_t *a) {
    __asm__ volatile("lock; decl %0" : "+m"(a->v));
}

/*!
 * \brief Exchange the values atomically
 *
 * \param n New value
 * \param a Pointer to atomic
 * \return Old value
 */
static inline int atomic32_xchg(int n, atomic32_t *a) {
    int old;
    __asm__ volatile("lock; xchgl %0, %1" : "+q"(old), "+m"(a->v) 
            : : "memory", "cc");
    return old;
}

/*!
 * \brief Compare and exchange the values atomically
 *
 * \param o Old value
 * \param n New value
 * \param a Pointer to atomic
 * \return Old value
 */
static inline int atomic32_cmpxchg(int o, int n, atomic32_t *a) {
    int old;
    __asm__ volatile("lock; cmpxchg %2, %1" : "=a"(old), "+m"(a->v) : 
            "r"(n), "a"(o) : "memory");
    return old;
}

#endif /* __ARCH_X86_KRNL4_SYNC__ATOMIC32_H_ */

