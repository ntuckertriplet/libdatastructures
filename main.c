#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedlist.h"
#include "maxheap.h"
#include "comparator.h"
#include "queue.h"

int main(int argc, char **argv) {
    minheap* heap = malloc(sizeof(minheap));
    heap->capacity = 15;
    heap->heap_size = 0;
    heap->elements = malloc(sizeof(void *) * heap->capacity);
    for (int i = 0; i < heap->capacity; i++) {
        heap->elements[i] = malloc(sizeof(void *));
    }

    printf("MADE THE HEAP\n");

    int to_add = 7;
    void* p = &to_add;
    heap_add(heap, p, sizeof(int), int_comp);

    to_add = 16;
    p = &to_add;
    heap_add(heap, p, sizeof(int), int_comp);

    to_add = 1;
    p = &to_add;
    heap_add(heap, p, sizeof(int), int_comp);

    to_add = 5;
    p = &to_add;
    heap_add(heap, p, sizeof(int), int_comp);

    to_add = 21;
    p = &to_add;
    heap_add(heap, p, sizeof(int), int_comp);

    to_add = 4;
    p = &to_add;
    heap_add(heap, p, sizeof(int), int_comp);

    printf("HEAP SIZE IS %d\n", heap->heap_size);

    for (int i = 0; i < heap->heap_size; i++) {
        printf("%d\n", (*(int * )heap->elements[i]));
    }

    void* found = delete_max(heap, sizeof(int), int_comp);
    printf("REMOVED %d\n", *(int * )found);
    for (int i = 0; i < heap->heap_size; i++) {
        printf("%d\n", (*(int * )heap->elements[i]));
    }

    queue* q = malloc(sizeof(queue));
    q->capacity = 15;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->elements = malloc(sizeof(void *) * q->capacity);
    for (int i = 0; i < q->capacity; i++) {
        q->elements[i] = malloc(sizeof(void *));
    }

    to_add = 4;
    p = &to_add;
    enqueue(q, p, sizeof(int));

    to_add = 5;
    p = &to_add;
    enqueue(q, p, sizeof(int));

    to_add = 7;
    p = &to_add;
    enqueue(q, p, sizeof(int));

    to_add = 12;
    p = &to_add;
    enqueue(q, p, sizeof(int));

    to_add = 1;
    p = &to_add;
    enqueue(q, p, sizeof(int));

    void* found2 = dequeue(q, sizeof(int));
    printf("%d\n", *(int * )found2);

    found2 = dequeue(q, sizeof(int));
    printf("%d\n", *(int * )found2);

    found2 = dequeue(q, sizeof(int));
    printf("%d\n", *(int * )found2);

    found2 = dequeue(q, sizeof(int));
    printf("%d\n", *(int * )found2);

    found2 = dequeue(q, sizeof(int));
    printf("%d\n", *(int * )found2);

    return 0;
}