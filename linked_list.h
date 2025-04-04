#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>

struct linked_list;  // Forward declaration only

struct linked_list *create_linked_list();
void insert_at_tail(struct linked_list *list, uint64_t value);
uint64_t remove_from_head(struct linked_list *list);
int is_empty(struct linked_list *list);
void free_linked_list(struct linked_list *list);

#endif
