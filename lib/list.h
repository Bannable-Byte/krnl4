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

#ifndef __LIB__LIST_H_
#define __LIB__LIST_H_

#include <assert.h>
#include <generic/macros.h>
#include <generic/poison.h>
#include <krnl4/types.h>

struct list_head {
    struct list_head *next, *prev;
};

/*
 * Initializes the list head structure
 * @name:   List variable name
 */
#define LIST_INIT(name) \
    { &name, &name }

/*
 * Declares a list variable and initializes it during compile time
 * @name:   List variable name
 */
#define LIST_HEAD(name) \
    struct list_head name = LIST_INIT(name)

/*
 * Adds new list item after the specified head
 * @new:    New item
 * @head:   List head pointer
 */
static inline void list_add(struct list_head *new, struct list_head *head) {
    assert(new != nullptr);
    assert(head != nullptr);
    assert(head->next != nullptr);
    if (head == nullptr || head->next == nullptr || new == nullptr)
        return;

    head->next->prev = new;
    new->next = head->next;
    new->prev = head;
    head->next = new;
}

/*
 * Deletes the element from the list
 * @head: List head pointer to remove from the list
 */
static inline void list_del(struct list_head *head) {
    assert(head != nullptr);
    assert(head->next != nullptr);
    assert(head->prev != nullptr);
    if (head == nullptr || head->next == nullptr || head->prev == nullptr)
        return;

    head->next->prev = head->prev;
    head->prev->next = head->next;
    head->next = head->prev = LIST_POISON_PTR;
}

/*
 * Tests if the list is empty
 * @list:   List head pointer
 * @return: Returns true if the list is empty, false if it's not
 */
static inline bool list_empty(struct list_head *list) {
    assert(list != nullptr);
    if (list == nullptr)
        return true;

    return list == list->next;
}

/*
 * Gets the containing structure this list item pointer has been embedded into
 * @ptr:    List head pointer
 * @type:   Type of the container
 * @member: The name of the list struct within the container
 */
#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

/*
 * Initializes the list during runtime
 * @list:   List head pointer
 */
static inline void list_init(struct list_head* list) {
    assert(list != nullptr);
    if (list == nullptr)
        return;

    list->next = list;
    list->prev = list;
}

#endif /* __LIB__LIST_H_ */

