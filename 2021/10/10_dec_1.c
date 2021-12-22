#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "stack/stack_definition.h"

#define MAX_LEN 1024

int do_error_score(char *buffer, Stack *stack) {
    
    int i = 0, error_score = 0;
    while(buffer[i] != '\n') {
        if(buffer[i] == ')' && peek(stack) != '(') {
            pop(stack);
            error_score += 3;
            break;
        } else if(buffer[i] == ']' && peek(stack) != '[') {
            pop(stack);
            error_score += 57;
            break;
        } else if(buffer[i] == '}' && peek(stack) != '{') {
            pop(stack);
            error_score += 1197;
            break;
        } else if(buffer[i] == '>' && peek(stack) != '<') {
            pop(stack);
            error_score += 25137;
            break;
        } else if(buffer[i] == '>' || buffer[i] == '}' || buffer[i] == ']' || buffer[i] == ')') { 
            pop(stack);
        } else  {
            push(stack, buffer[i]);
        }
        i++;
    }

    return error_score;
}


int main() {

    FILE *fp;
    fp = fopen("input_2", "r");
    char buffer[MAX_LEN];
    Stack *stack;
    int error_score = 0;
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    stack = createStack(MAX_LEN);
    while(fgets(buffer, MAX_LEN, fp)) {
        error_score += do_error_score(buffer, stack);
    }

    freeStack(stack);
    fclose(fp);
    printf("Error score = %d\n", error_score);

    return 0;
}
