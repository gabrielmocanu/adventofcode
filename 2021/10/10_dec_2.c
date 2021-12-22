#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "stack/stack_definition.h"

#define MAX_LEN 4096

unsigned long long autocomplete_score[MAX_LEN];

int cmp_function (const void * a, const void * b) {
    unsigned long long auul = *(unsigned long long *)a;
    unsigned long long buul = *(unsigned long long *)b;

    if( auul < buul ) {
        return -1;
    }
    else if( auul > buul ) {
        return 1;
    }
    else {
        return 0;
    }
}


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

int do_autocomplete(char *buffer, Stack *stack, int autocomplete_row) {

    int i = 0, aux; 
    unsigned long long error_score = 0;
    while(buffer[i] != '\n') {
        if(buffer[i] == '>' || buffer[i] == '}' || buffer[i] == ']' || buffer[i] == ')') { 
            pop(stack);
        } else  {
            push(stack, buffer[i]);
        }
        i++;
    }

    while(!isEmpty(stack)) {
        aux = pop(stack);
        if(aux == '(') { 
            error_score = 5 * error_score + 1;
        } else if (aux == '[' ) {
            error_score = 5 * error_score + 2;
        } else if (aux == '{' ) {
            error_score = 5 * error_score + 3;            
        } else {
            error_score = 5 * error_score + 4;        
        }
    }

    autocomplete_score[autocomplete_row] = error_score;
    return error_score;
}


int main() {

    FILE *fp;
    fp = fopen("input_2", "r");
    int j = 0;
    char buffer[MAX_LEN];
    Stack *stack;
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    stack = createStack(MAX_LEN);
    while(fgets(buffer, MAX_LEN, fp)) {
        if(do_error_score(buffer, stack)) {
            continue;
        }
        while(!isEmpty(stack)) {
            pop(stack);
        }
        do_autocomplete(buffer, stack, j);
        j++;
    }

    qsort(autocomplete_score, 47, sizeof(unsigned long long), cmp_function);

    freeStack(stack);
    fclose(fp);
    printf("Autocomplete error score = %llu\n", autocomplete_score[j/2]);

    return 0;
}
