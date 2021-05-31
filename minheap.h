#ifndef MINHEAP_H
#define MINHEAP_H

typedef struct minheap {
    void** elements;
    int heap_size;
    int capacity;
} minheap;

int heap_size(minheap* heap);
void heap_add(minheap* heap, void* data, size_t size, int (*compar)(const void *, const void *));
void* get_min(minheap* heap);

#endif