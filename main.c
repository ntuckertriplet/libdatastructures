#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "queue.h"

int main(int argc, char **argv) {
    queue* q = malloc(sizeof(queue));
    q->capacity = 15;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->elements = malloc(sizeof(void *) * q->capacity);
    for (int i = 0; i < q->capacity; i++) {
        q->elements[i] = malloc(sizeof(void *));
    }

    int to_add = 4;
    void* data = &to_add;
    enqueue(q, data, sizeof(int));

    to_add = 5;
    data = &to_add;
    enqueue(q, data, sizeof(int));

    to_add = 6;
    data = &to_add;
    enqueue(q, data, sizeof(int));

    to_add = 7;
    data = &to_add;
    enqueue(q, data, sizeof(int));

    to_add = 8;
    data = &to_add;
    enqueue(q, data, sizeof(int));

    for (int i = 0; i < q->size; i++) {
        printf("%d\n", *(int *)q->elements[i]);
    }

    void* found = dequeue(q, sizeof(int));
    printf("FOUND DEQUEUE'D %d\n", *(int *)found);

    memcpy(found, dequeue(q, sizeof(int)), sizeof(int));
    printf("FOUND DEQUEUE'D %d\n", *(int *)found);

    found = dequeue(q, sizeof(int));
    printf("FOUND DEQUEUE'D %d\n", *(int *)found);

    found = dequeue(q, sizeof(int));
    printf("FOUND DEQUEUE'D %d\n", *(int *)found);

    found = dequeue(q, sizeof(int));
    printf("FOUND DEQUEUE'D %d\n", *(int *)found);

    return 0;
}