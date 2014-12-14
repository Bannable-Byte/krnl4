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
 * \file krnl4.c
 * \brief Kernel bootstrapping
 */

#include <assert.h>
#include <generic/macros.h>
#include <krnl4/cpu/cpu.h>
#include <krnl4/cpu/irq.h>
#include <krnl4/sync/atomic32.h>

/*!
 * \brief Kernel loader. Kernel bootstrapping start here.
 *
 * Machine state after multiboot
 * ======================================================
 *
 * When the boot loader invokes the 32-bit operating system, the machine must 
 * have the following state:
 *
 * ‘EAX’
 * Must contain the magic value ‘0x2BADB002’; the presence of this value 
 * indicates to the operating system that it was loaded by a Multiboot-compliant 
 * boot loader (e.g. as opposed to another type of boot loader that the operating 
 * system can also be loaded from). 
 *
 * ‘EBX’
 * Must contain the 32-bit physical address of the Multiboot information 
 * structure provided by the boot loader (see Boot information format). 
 *
 * ‘CS’
 * Must be a 32-bit read/execute code segment with an offset of ‘0’ and a limit 
 * of ‘0xFFFFFFFF’. The exact value is undefined. 
 *
 * ‘DS’
 * ‘ES’
 * ‘FS’
 * ‘GS’
 * ‘SS’
 * Must be a 32-bit read/write data segment with an offset of ‘0’ and a limit 
 * of ‘0xFFFFFFFF’. The exact values are all undefined. 
 *
 * ‘A20 gate’
 * Must be enabled. 
 *
 * ‘CR0’
 * Bit 31 (PG) must be cleared. Bit 0 (PE) must be set. Other bits are all 
 * undefined. 
 *
 * ‘EFLAGS’
 * Bit 17 (VM) must be cleared. Bit 9 (IF) must be cleared. Other bits are all 
 * undefined.
 *
 * All other processor registers and flag bits are undefined. This includes, 
 * in particular:
 *
 * ‘ESP’
 * The OS image must create its own stack as soon as it needs one. 
 *
 * ‘GDTR’
 * Even though the segment registers are set up as described above, the ‘GDTR’ 
 * may be invalid, so the OS image must not load any segment registers 
 * (even just reloading the same values!) until it sets up its own ‘GDT’. 
 *
 * ‘IDTR’
 * The OS image must leave interrupts disabled until it sets up its own IDT.
 *
 * However, other machine state should be left by the boot loader in normal 
 * working order, i.e. as initialized by the bios (or DOS, if that's what the 
 * boot loader runs from). In other words, the operating system should be able 
 * to make bios calls and such after being loaded, as long as it does not 
 * overwrite the bios data structures before doing so. Also, the boot loader 
 * must leave the pic programmed with the normal bios/DOS values, even if it 
 * changed them during the switch to 32-bit mode.
 */
void __krnl4_loader() __attribute__((noreturn)); 
void __krnl4_loader() {
    int err;
    struct cpu cpu;

    /* Disable local IRQs */
    irq_disable();

    /* Bootstrap the CPU */
    err = cpu_init(&cpu);
    assert_panic(err != 0);

    err = cpu_bootstrap(&cpu);
    assert_panic(err != 0);

    /* Re-enable local IRQs */
    irq_enable();

    /* Never fall through */
    spin_forever();
}
