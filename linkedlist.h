#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    void *data;
    struct node *next;
} node;

void list_add(node* head, void* data, size_t size);
void* get(node* head, int index);
int contains(node* head, void* data, int (*compar)(const void *, const void*));
int index_of(node* head, void* data, int (*compar)(const void *, const void*));

#endif