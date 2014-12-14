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

/*!
 * \file multiboot.h
 * \brief krnl4 multiboot
 */

#ifndef __INIT__MULTIBOOT_H_
#define __INIT__MULTIBOOT_H_

#include <krnl4/types.h>

/*!
 * \brief The magic number for the Multiboot header 
 */
#define MULTIBOOT_HEADER_MAGIC 0x1BADB002

/*!
 * \brief The magic number passed by a Multiboot-compliant boot loader 
 */
#define MULTIBOOT_BOOTLOADER_MAGIC 0x2BADB002

/*!
 * \brief Multiboot information structure mem_* fields are valid 
 */
#define MBI_FLAG_MEM 0x00000001

/*!
 * \brief Multiboot information structure boot_device field is valid 
 */
#define MBI_FLAG_BOOTDEV 0x00000002

/*!
 * \brief Multiboot information structure cmdline field is valid 
 */
#define MBI_FLAG_CMDLINE 0x00000004

/*!
 * \brief Multiboot information structure module fields are valid 
 */
#define MBI_FLAG_MODS 0x00000008

/*!
 * \brief Multiboot information structure a.out symbol table is valid 
 */
#define MBI_FLAG_AOUT 0x00000010

/*!
 * \brief Multiboot information struture ELF section header table is valid 
 */
#define MBI_FLAG_ELF 0x00000020

/*!
 * \brief Multiboot information structure memory map is valid 
 */
#define MBI_FLAG_MMAP 0x00000040

/*!
 * \brief Multiboot information structure drive list is valid 
 */
#define MBI_FLAG_DRIVES 0x00000080

/*!
 * \brief Multiboot information structure ROM configuration field is valid 
 */
#define MBI_FLAG_CFGTBL 0x00000100

/*!
 * \brief Multiboot information structure boot loader name field is valid 
 */
#define MBI_FLAG_LOADER 0x00000200

/*!
 * \brief Multiboot information structure APM table is valid 
 */
#define MBI_FLAG_APM 0x00000400

/*!
 * \brief Multiboot information structure video information is valid 
 */
#define MBI_FLAG_VBE 0x00000800

/*!
 * \brief Memory segment is available 
 */
#define MBI_MMAP_AVAIL 0x00000001

/*!
 * \brief Multiboot header 
 */
struct multiboot_header {
    uint32_t magic;
    uint32_t flags;
    uint32_t checksum;
    uint32_t header_addr;
    uint32_t load_addr;
    uint32_t load_end_addr;
    uint32_t bss_end_addr;
    uint32_t entry_addr;
} __attribute__ (( packed, may_alias ));

/*!
 * \brief Multiboot module structure 
 */
struct multiboot_module {
    uint32_t mod_start;
    uint32_t mod_end;
    uint32_t string;
    uint32_t reserved;
} __attribute__((packed, may_alias));

/*!
 * \brief Multiboot memory map entry 
 */
struct multiboot_memory_map {
    uint32_t size;
    uint64_t base_addr;
    uint64_t length;
    uint32_t type;
} __attribute__((packed, may_alias));

/*!
 * \brief Multiboot a.out symbol table 
 */
struct multiboot_aout_symbol_table {
    uint32_t tabsize;
    uint32_t strsize;
    uint32_t addr;
    uint32_t reserved;
} __attribute__((packed, may_alias));

/*!
 * \brief Multiboot ELF section header table 
 */
struct multiboot_elf_section_header_table {
    uint32_t num;
    uint32_t size;
    uint32_t addr;
    uint32_t shndx;
} __attribute__((packed, may_alias));

/*!
 * \brief Multiboot information structure 
 */
struct multiboot_info {
    uint32_t flags;
    uint16_t mem_lower;
    uint16_t mem_upper;
    uint8_t bios_drive;
    uint8_t sub_part;
    uint8_t part;
    uint8_t drive;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    union {
        struct multiboot_aout_symbol_table aout_syms;
        struct multiboot_elf_section_header_table elf_sections;
    } syms;
    uint32_t mmap_length;
    uint32_t mmap_addr;
    uint32_t drives_length;
    uint32_t drives_addr;
    uint32_t config_table;
    uint32_t boot_loader_name;
    uint32_t apm_table;
    uint32_t vbe_control_info;
    uint32_t vbe_mode_info;
    uint16_t vbe_mode;
    uint16_t vbe_interface_seg;
    uint16_t vbe_interface_off;
    uint16_t vbe_interface_len;
};

/*!
 * \brief Returns the pointer to the multiboot information structure 
 */
struct multiboot_info* multiboot_prepare();

#endif /* __INIT__MULTIBOOT_H_ */

