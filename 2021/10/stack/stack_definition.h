#ifndef STACK_DEFINITION
#define STACK_DEFINITION

typedef struct Stack {
    unsigned capacity;
    unsigned size;
    int *array;
} Stack;

Stack *createStack(unsigned capacity);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, int nr);
int pop(Stack *stack);
int peek(Stack *stack);
void freeStack(Stack *stack);


#endif
