#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "queue.h"

/**
 * Determines if the queue is empty or not
 * 
 * @param queue the queue to query
 * 
 * @returns an integer 1 if it is empty, 0 if it is not
 */
int is_empty(queue *queue)
{
    if (queue->size == 0)
    {
        return 1;
    }

    return 0;
}

/**
 * Determines if the queue is full or not
 * 
 * @param queue the queue to query
 * 
 * @returns an integer 1 if it is full, 0 if it is not
 */
int is_full(queue *queue)
{
    if (queue->size == queue->capacity)
    {
        return 1;
    }

    return 0;
}

/**
 * Retreive, but do not delete, the element at the front of the queue
 * 
 * @param queue the queue to peek
 * 
 * @returns the void* item at the front of the queue
 */
void *peek(queue *queue)
{
    return queue->elements[queue->front];
}

/**
 * Adds an item to the front of the queue
 * 
 * @param q the queue to add to
 * @param data the data to add to the queue
 * @param size the size_t of the data to add
 */
void enqueue(queue *q, void *data, size_t size)
{
    if (!is_full(q))
    {
        memcpy(q->elements[q->rear], data, size);
        q->rear++;
        q->size++;
    }
}

/**
 * Removes an item from the FIFO queue
 * 
 * @param queue the queue dequeue from
 * @param size the size_t of the data to dequeue
 * 
 * @returns the data in a void*
 */
void *dequeue(queue *queue, size_t size)
{
    void *dequeue = malloc(sizeof(size));
    memcpy(dequeue, queue->elements[queue->front], size);

    if (queue->front == queue->capacity)
    {
        return NULL;
    }

    queue->front++;
    queue->size--;
    return dequeue;
}