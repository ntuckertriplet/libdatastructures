#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "queue.h"

int is_empty(queue* queue) {
    if (queue->size == 0) {
        return 1;
    }

    return 0;
}

int is_full(queue* queue) {
    if (queue->size == queue->capacity) {
        return 1;
    }

    return 0;
}

void* peek(queue* queue) {
    return queue->elements[0];
}

void enqueue(queue* q, void* data, size_t size) {
    if (!is_full(q)) {
        memcpy(q->elements[q->rear], data, size);
        q->rear++;
        q->size++;
    }
}

void* dequeue(queue* queue, size_t size) {
    void* dequeue = malloc(sizeof(size));
    memcpy(dequeue, queue->elements[queue->front], size);

    if (queue->front == queue->capacity) {
        return NULL;
    }

    queue->front++;
    queue->size--;
    return dequeue;
}