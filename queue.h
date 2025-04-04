#ifndef QUEUE_H
#define QUEUE_H

#include "tile_game.h"
#include "linked_list.h"

struct queue {
    struct linked_list *list;
};

struct queue *create_queue();
void enqueue(struct queue *q, struct game_state state);
int number_of_moves(struct game_state start);
struct game_state dequeue(struct queue *q);
int is_queue_empty(struct queue *q);
void free_queue(struct queue *q);

#endif