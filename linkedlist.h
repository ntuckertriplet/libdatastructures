#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linked_list {
    struct node* head;
    int size;
} linked_list;

typedef struct node {
    void *data;
    struct node *next;
} node;

void list_add(linked_list* list, void* data, size_t size);
void* get(linked_list* list, int index);
int contains(linked_list* list, void* data, int (*compar)(const void *, const void*));
int index_of(linked_list* list, void* data, int (*compar)(const void *, const void*));

#endif