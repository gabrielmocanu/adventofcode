#include "stack_definition.h"
#include <stdio.h>
#include <stdlib.h>

Stack* createStack(unsigned capacity) {
    Stack *stack = calloc(1, sizeof(struct Stack));
    stack->capacity = capacity;
    stack->size = 0;
    stack->array = calloc(capacity, sizeof(int));
    return stack;
}

int isFull(Stack *stack) {
    return stack->size == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->size == 0;
}

void push(Stack *stack, int nr) {

    if(isFull(stack)) {
        stack->capacity *= 2;
        stack->array = realloc(stack->array, stack->capacity * sizeof(int));
    }
    stack->array[stack->size] = nr;
    stack->size++;
}

int pop(Stack *stack) {

    if(isEmpty(stack))
        return -1;
    stack->size--;
    return stack->array[stack->size];
}

int peek(Stack *stack) {
    
    if(isEmpty(stack))
        return -1;
    return stack->array[stack->size-1];

}

void freeStack(Stack *stack) {
    free(stack->array);
    free(stack);
}

