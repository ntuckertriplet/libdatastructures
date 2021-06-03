#include <stdlib.h>
#include <string.h>

#include "stack.h"

/**
 * Determines if the stack is full
 * 
 * @param stack the stack to query
 * @returns 1 if it is full, 0 if it is not
 */ 
int stack_is_full(stack* stack) {
    return (stack->top == stack->capacity - 1);
}

/**
 * Determines if the stack is empty
 * 
 * @param stack the stack to query
 * @returns 1 if it is empty, 0 if it is not
 */ 
int stack_is_empty(stack* stack) {
    return (stack->top == -1);
}

/**
 * Push an item on the top of the stack
 * 
 * @param stack the stack to add to
 * @param data the void* data to add
 * @param size the size_t of the data to add
 */ 
void stack_push(stack* stack, void* data, size_t size) {
    if (!stack_is_full(stack)) {
        stack->data[stack->top + 1] = malloc(size);
        memcpy(stack->data[stack->top + 1], data, size);
        stack->top++;
    }
}

/**
 * Pop an item off the top of the stack
 * 
 * @param stack the stack to pop from
 * @param size the size_t of the data to pop
 */ 
void* stack_pop(stack* stack, size_t size) {
    void* popped = malloc(size);
    memcpy(popped, stack->data[stack->top], size);
    free(stack->data[stack->top]);
    stack->top--;
    return popped;
}

/**
 * Peek the item on the top of the stack but do not remove
 * 
 * @param stack the stack to peek from
 */ 
void* stack_peek(stack* stack) {
    return stack->data[stack->top];
}