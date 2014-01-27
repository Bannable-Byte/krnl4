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

#include "multiboot.h"

#include <krnl4/types.h>

word_t __multiboot_magic;
word_t __multiboot_ptr;

struct multiboot_info *multiboot_prepare() {
    if (__multiboot_magic == MULTIBOOT_BOOTLOADER_MAGIC)
    	return (struct multiboot_info*)__multiboot_ptr;

    return nullptr;
}

