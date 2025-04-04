#include <stdlib.h>
#include "queue.h"
#include "linked_list.h"
#include "tile_game.h"



struct queue *create_queue() {
    struct queue *q = malloc(sizeof(struct queue));
    q->list = create_linked_list();
    return q;
}

void enqueue(struct queue *q, struct game_state state) {
    uint64_t serialized = serialize(state);
    insert_at_tail(q->list, serialized);
}

struct game_state dequeue(struct queue *q) {
    uint64_t serialized = remove_from_head(q->list);
    return deserialize(serialized);
}

int is_queue_empty(struct queue *q) {
    return is_empty(q->list);
}

void free_queue(struct queue *q) {
    free_linked_list(q->list);
    free(q);
}

int number_of_moves(struct game_state start) {
    struct queue *q = create_queue();
    enqueue(q, start);

    struct game_state current;
    while (!is_queue_empty(q)) {
        current = dequeue(q);

        if (is_solved(current)) {  // Assume is_solved checks if the game is solved
            free_queue(q);
            return current.num_steps;
        }

        // Generate possible moves
        struct game_state next_state = current;
        move_up(&next_state);
        if (next_state.num_steps > current.num_steps) enqueue(q, next_state);

        next_state = current;
        move_down(&next_state);
        if (next_state.num_steps > current.num_steps) enqueue(q, next_state);

        next_state = current;
        move_left(&next_state);
        if (next_state.num_steps > current.num_steps) enqueue(q, next_state);

        next_state = current;
        move_right(&next_state);
        if (next_state.num_steps > current.num_steps) enqueue(q, next_state);
    }

    free_queue(q);
    return -1;  // No solution found
}
