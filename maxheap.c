#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "maxheap.h"

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

void percolate_down(minheap* heap, int index, size_t size, int (*compar)(const void *, const void *)) {
    int left_index = (index * 2) + 1;
    int right_index = (index * 2) + 2;

    void* current = heap->elements[index];
    void* left = heap->elements[left_index];
    void* right = heap->elements[right_index];

    if (left_index < heap->heap_size && (*compar)(current, left) < 0) {
        swap(current, left, size);
        percolate_down(heap, (index * 2) + 1, size, (*compar));
    }

    if (right_index < heap->heap_size && (*compar)(current, right) < 0) {
        swap(current, right, size);
        percolate_down(heap, (index * 2) + 2, size, (*compar));
    }
}

int heap_size(minheap* heap) {
    if (heap == NULL) {
        return -1;
    }

    return heap->heap_size;
}

void heap_add_all(minheap* heap, void** data, size_t size, int num_elems, int (*compar)(const void *, const void *)) {
    if (heap == NULL) {
        return;
    }

    if (heap->heap_size > 0) {
        return;
    }

    if (num_elems > heap->capacity) {
        return;
    }

    for (int i = 0; i < num_elems; i++) {
        heap->elements[i] = malloc(size);
        memcpy(heap->elements[i], data[i], size);
    }

    if (num_elems < 2) {
        return;
    }

    int index = (num_elems - 2) / 2;
    for (int i = index; i >= 0; i--) {
        percolate_down(heap, i, size, (*compar));
    }
}

void heap_add(minheap* heap, void* data, size_t size, int (*compar)(const void *, const void *)) {
    if (heap == NULL) {
        return;
    }

    if (heap->heap_size == heap->capacity) {
        return;
    }

    memcpy(heap->elements[heap->heap_size], data, size);

    heap->heap_size++;

    // percolate up
    int child = heap->heap_size - 1;
    int parent = (heap->heap_size - 2) / 2;

    while ((*compar)(heap->elements[child], heap->elements[parent]) > 0) {
        swap(heap->elements[child], heap->elements[parent], size);
        child = parent;
        parent = (parent - 1) / 2;
    }
}

void* get_max(minheap* heap) {
    if (heap == NULL) {
        return NULL;
    }

    return heap->elements[0];
}

void* delete_max(minheap* heap, size_t size, int (*compar)(const void *, const void *)) {
    if (heap == NULL) {
        return NULL;
    }

    void* found = malloc(sizeof(void *));
    memcpy(found, heap->elements[0], size);

    swap(heap->elements[0], heap->elements[heap->heap_size - 1], size);

    free(heap->elements[heap->heap_size - 1]);
    heap->heap_size--;

    percolate_down(heap, 0, size, (*compar));

    return found;
}