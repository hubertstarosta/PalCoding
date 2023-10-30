#include "queue.h"
#include <stdlib.h>


void init_queue(struct queue *q) {
    q->data = NULL;
    q->capacity = 0;
    q->offset = 0;
    q->length = 0;
}

void clear_queue(struct queue *q) {
    if (q->data != NULL) {
        free(q->data);
        init_queue(q);
    }
}

void enqueue(struct queue *q, int value) {
    // TODO: Task 1: add an element to the circular queue.
    //if there is space in the queue perform an if function
    if (q->length == q->capacity) {
        if (q->capacity == 0) {
            q->capacity = 1; // initialize with a capacity of 1
        } else {
            q->capacity *= 2; // double the capacity
        }

        q->data = realloc(q->data, q->capacity * sizeof(int));

    }
        //the sum of the first item in the queue + the amount of values in the queue mod the size is the last index (end)
        q->data[(q->offset + q->length) % q->capacity] = value;
        q->length++;

}

bool queue_empty(struct queue *q) {
    // TODO: Task 1: check whether the queue is empty.
    return(q->length == 0);
}

bool dequeue(struct queue *q, int *out) {
    // TODO: Task 1: remove an element from the circular queue.
    if (queue_empty(q)){
        return false;
    }
    *out = q->data[q->offset];
    q->offset = (q->offset + 1) % q->capacity;
    q->length--;
    if(q->length <=q->capacity / 4 && q->capacity>2) {
        q->capacity = q->capacity / 2;
        q->data = realloc(q->data, q->capacity * sizeof(int));
    }
    return true;
}

