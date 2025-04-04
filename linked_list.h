#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>  // Needed for bool

struct node;

struct linked_list {
    struct node *head;
    struct node *tail;
};

// Function declarations
struct linked_list *create_linked_list(void);
bool is_empty(struct linked_list *list);
void free_linked_list(struct linked_list *list);
void insert_at_tail(struct linked_list *list, size_t value);
size_t remove_from_head(struct linked_list *list);

#endif // LINKED_LIST_H