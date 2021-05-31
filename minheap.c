#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "minheap.h"

void swap(void * a, void * b, size_t len)
{
    unsigned char * p = a, * q = b, tmp;
    for (size_t i = 0; i != len; ++i)
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

int heap_size(minheap* heap) {
    if (heap == NULL) {
        return -1;
    }

    return heap->heap_size;
}

void heap_add(minheap* heap, void* data, size_t size, int (*compar)(const void *, const void *)) {
    if (heap == NULL) {
        return;
    }

    if (heap->heap_size == heap->capacity) {
        return;
    }

    heap->elements[heap->heap_size] = data;
    heap->heap_size++;

    // percolate up
    int child = heap->heap_size - 1;
    int parent = (heap->heap_size - 2) / 2;

    while ((*compar)(heap->elements[child], heap->elements[parent]) < 0) {
        swap(heap->elements[child], heap->elements[parent], size);
        child = parent;
        parent = (parent - 1) / 2;
    }
}

void* get_min(minheap* heap) {
    if (heap == NULL) {
        return NULL;
    }

    return heap->elements[0];
}