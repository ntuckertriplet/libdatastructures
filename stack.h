#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int top;
    int capacity;
    void** data;
} stack;

int stack_is_full(stack* stack);
int stack_is_empty(stack* stack);
void stack_push(stack* stack, void* data, size_t size);
void* stack_pop(stack* stack, size_t size);
void* stack_peek(stack* stack);

#endif