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
    printf("QUEUE SIZE IS %d AND CAPACITY IS %d\n", queue->size, queue->capacity);
    if (queue->size == queue->capacity) {
        return 1;
    }

    return 0;
}

void* peek(queue* queue) {
    return queue->elements[0];
}

void enqueue(queue* q, void* data, size_t size) {
    if (q->size == q->capacity) {
        printf("QUEUE STILL HAS SPACE\n");
        printf("ADDING DATA %d\n", *(int *)data);
        memcpy(q->elements[q->rear], data, size);
        q->rear++;
        q->size++;
        printf("ADDED THE DATA SUCCESSFULLY\n");
    }
    printf("QUEUE IS FULL WITH SIZE %d AND CAPACITY %d\n", q->size, q->capacity);
}

void* dequeue(queue* queue, size_t size) {
    void* dequeue = malloc(sizeof(void *));
    memcpy(dequeue, queue->elements[0], size);

    if (queue->front == queue->capacity) {
        queue->front = 0;
    }

    queue->size--;
    return dequeue;
}