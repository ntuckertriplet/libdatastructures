#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"
#include "minheap.h"
#include "comparator.h"
#include "priorityqueue.h"

int main(int argc, char **argv) {

    node* list = malloc(sizeof(node));
    list->data = NULL;
    list->next = NULL;

    int to_add = 5;
    void* p = &to_add;

    list_add(list, p, sizeof(int));
    list_add(list, p, sizeof(int));
    list_add(list, p, sizeof(int));
    list_add(list, p, sizeof(int));

    to_add = 6;
    p = &to_add;

    list_add(list, p, sizeof(int));

    int look = 4;
    void* p2 = &look;

    int contain = contains(list, p, int_comp);
    printf("%d\n", contain);

    contain = contains(list, p2, int_comp);
    printf("%d\n", contain);

    node* cur_node = list;
    while (cur_node != NULL) {
        int* val = (int *)cur_node->data;
        printf("%d\n", (*val));
        cur_node = cur_node->next;
    }

    int* got = (int *)get(list, 4);
    printf("%d\n", (*got));

    minheap* heap = malloc(sizeof(minheap));
    heap->capacity = 15;
    heap->heap_size = 0;
    heap->elements = malloc(sizeof(void *) * heap->capacity);

    printf("MADE THE HEAP\n");

    heap_add(heap, p, sizeof(int), int_comp);

    to_add = 7;
    p = &to_add;
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

    to_add = 20;
    p = &to_add;
    heap_add(heap, p, sizeof(int), int_comp);

    to_add = 4;
    p = &to_add;
    heap_add(heap, p, sizeof(int), int_comp);

    printf("HEAP SIZE IS %d\n", heap->heap_size);

    for (int i = 0; i < heap->heap_size; i++) {
        printf("%d\n", (*(int * )heap->elements[i]));
    }

    void* found = delete_min(heap, sizeof(int), int_comp);
    printf("REMOVED %d\n", *(int * )found);
    for (int i = 0; i < heap->heap_size; i++) {
        printf("%d\n", (*(int * )heap->elements[i]));
    }

    return 0;
}