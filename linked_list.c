#include <stdint.h>
#include <stdlib.h>
#include "linked_list.h"

struct node {
    uint64_t data;
    struct node *next;
};



struct linked_list *create_linked_list() {
    struct linked_list *list = malloc(sizeof(struct linked_list));
    list->head = list->tail = NULL;
    return list;
}

void insert_at_tail(struct linked_list *list, size_t value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (list->tail == NULL) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

uint64_t remove_from_head(struct linked_list *list) {
    if (list->head == NULL) return 0;

    struct node *temp = list->head;
    uint64_t value = temp->data;
    list->head = temp->next;

    if (list->head == NULL) {
        list->tail = NULL;
    }

    free(temp);
    return value;
}

bool is_empty(struct linked_list *list) {
    return list->head == NULL;
}

void free_linked_list(struct linked_list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
