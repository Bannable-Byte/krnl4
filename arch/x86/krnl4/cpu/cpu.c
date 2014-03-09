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

#include <assert.h>
#include <krnl4/types.h>
#include "cpu.h"

static int gdt_init(struct segdesc *gdt) {
    return ECPU;
}

static int idt_init(struct segdesc *idt) {
    return ECPU;
}

int cpu_init(struct cpu *cpu) {
    assert(cpu != nullptr);
    if (cpu == nullptr)
        return ECPU;

    int err = ENO;
    if ((err = gdt_init(cpu->gdt)) != ENO)
        return err;

    if ((err = idt_init(cpu->idt)) != ENO)
        return err;

    return ENO;
}

int cpu_boostrap(struct cpu *cpu) {
    return ECPU;
}

