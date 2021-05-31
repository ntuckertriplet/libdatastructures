#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedlist.h"

void list_add(node* head, void* data, size_t size) {
    if (head->data == NULL) {
        head->data = malloc(size);
        memcpy(head->data, data, size);
        return;
    }

    node* to_add = malloc(sizeof(node));
    to_add->data = malloc(size);
    memcpy(to_add->data, data, size);
    to_add->next = NULL;

    node* cur_node = head;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }

    cur_node->next = to_add;
}

void* get(node* head, int index) {
    if (head == NULL) {
        return NULL;
    }

    int i = 0;
    node* cur_node = head;

    while (cur_node != NULL) {
        if (i == index) {
            return cur_node->data;
        }

        cur_node = cur_node->next;
        i++;
    }

    return NULL;
}

int contains(node* head, void* data, int (*compar)(const void *, const void *)) {
    if (head == NULL) {
        return -1;
    }

    node* cur_node = head;
    while (cur_node != NULL) {
        if ((*compar)(cur_node->data, data) == 0) {
            return 1;
        }

        cur_node = cur_node->next;
    }

    return -1;
}

int index_of(node* head, void* data, int (*compar)(const void *, const void*)) {
    if (head == NULL || data == NULL) {
        return -1;
    }
    
    int i = 0;
    node* cur_node = head;
    while(cur_node != NULL) {
        if ((*compar)(cur_node->data, data) == 0) {
            return i;
        }

        i++;
        cur_node = cur_node->next;
    }

    return -1;
}