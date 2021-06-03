#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linkedlist.h"

/**
 * Add item to the list
 * 
 * @param head the head node of the linked list
 * @param data the data in a void * to add
 * @param size the size_t of the data to add
 */ 
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

/**
 * Get an item in the list at the index provided
 * 
 * @param head the head of the linked list
 * @param index the index to retreive from
 * 
 * @returns void * containing the data or NULL of the index is not valid
 */ 
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

/**
 * Determine if the list contains a particular value
 * 
 * @param head the head of the linked list
 * @param data the void* data to check if it is in the linked list
 * @param compar* a custom comparator to be passed in
 * 
 * @returns 1 if the list contains the data, 0 if not
 */
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

/**
 * Get the index of particular data
 * 
 * @param head the head of the linked list
 * @param data the void* data to check the index of
 * @param compar* a custom comparator to be passed in
 * 
 * @returns the index of the data, or -1 if not in the list
 */
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