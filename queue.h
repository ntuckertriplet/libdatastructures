#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue {
    void **elements;
    int capacity;
    int front;
    int rear;
    int size;
} queue;

int is_empty(queue* queue);
int is_full(queue* queue);
void* peek(queue* queue);
void enqueue(queue* queue, void* data, size_t size);
void* dequeue(queue* queue, size_t size);

#endif