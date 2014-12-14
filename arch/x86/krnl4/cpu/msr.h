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
 * \file msr.h
 * \brief Model specific register for the Intel x86 architecture
 */

#ifndef __ARCH_X86_KRNL4_CPU__MSR_H_
#define __ARCH_X86_KRNL4_CPU__MSR_H_

#include <krnl4/types.h>

/*!
 * \brief Map of base address of FS (r/w) 
 */
#define IA32_FS_BASE    0xc0000100

/*!
 * \brief Map of base address of GS (r/w) 
 */
#define IA32_GS_BASE    0xc0000101


/*!
 * \brief Reads the value of the specified model specific register 
 *
 * \param msr Model specific register address
 * \return 64bit value
 */
inline uint64_t read_msr(uint32_t msr) {
    uint32_t low, high;
    __asm__ __volatile__(
            "rdmsr\n"
            : "=a"(low)
            , "=d"(high)
            : "c"(msr)
    );

    return (((uint64_t)high) << 32) | (uint64_t)low;
}

/*!
 * \brief Writes the value to the specified model specific register
 *
 * \param msr Model specific register address
 * \param value 64bit value
 */
inline void write_msr(uint32_t msr, uint64_t value) {
    __asm__ __volatile__(
            "wrmsr\n"
            : /* no output */ 
            : "a"((uint32_t)value)
            , "c"(msr)
            , "d"((uint32_t)(value >> 32))
    );
}

#endif /* __ARCH_X86_KRNL4_CPU__MSR_H_ */ 

