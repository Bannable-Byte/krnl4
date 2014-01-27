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

/*
 * Complete multiboot specification can be found here:
 * http://www.gnu.org/software/grub/manual/multiboot/multiboot.html
 */

    .equ MULTIBOOT_MAGIC, 0x1BADB002
    .equ MULTIBOOT_FLAGS, 0x00000000
    .equ STACK_SIZE, 0x2000 /* 8K stack space */

    .text
    .global __krnl4_start

__krnl4_start:
    /*
     * Multiboot handler. Kernel starts here.
     *
     * EAX - 0x2BADB002 if loaded by a multiboot loader
     * EBX - multiboot info structure pointer if loaded by a multiboot loader
     */
    movl %eax, __multiboot_magic
    movl %ebx, __multiboot_ptr
    movl %eax, %esi
    movl %ebx, %edi
    cli
    cld
_start:

    /* Load temporary stack pointer */
    lea __krnl4_mini_stack, %esp

    /* Start kernel */
    call __krnl4_loader

1:
    /* Kernel never returns here */
    jmp 1b
  
    .align 16
    .space STACK_SIZE
__krnl4_mini_stack:

    .section .multiboot
  
    /* Jump to the multiboot handler */
    jmp __krnl4_start

    .ascii "KRNL4"
    .align 16, 90

__krnl4_mb_header:
    .long MULTIBOOT_MAGIC             /* magic */
    .long MULTIBOOT_FLAGS             /* flags */
    .long -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)  /* checksum */
    .long __krnl4_mb_header           /* header_addr */

