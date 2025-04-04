#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "linked_list.h"

// Node structure definition
struct node {
    uint64_t data;
    struct node *next;
};

// Create and initialize a new linked list
struct linked_list *create_linked_list(void) {
    struct linked_list *list = malloc(sizeof(struct linked_list));
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

// Insert a new node at the tail of the list
void insert_at_tail(struct linked_list *list, uint64_t value) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) return;  // Optionally handle malloc failure

    new_node->data = value;
    new_node->next = NULL;

    if (list->tail == NULL) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Remove and return the value from the head of the list
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

// Check if the list is empty
bool is_empty(struct linked_list *list) {
    return list->head == NULL;
}

// Free all nodes and the list structure
void free_linked_list(struct linked_list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);

  }
