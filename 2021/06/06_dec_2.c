#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define LEN 10000
#define DAYS 256

void print_array(unsigned long long *array, int len) {
    int i;

    for(i = 0; i < len; i++) {
        printf("%llu ", array[i]);
    }
    printf("\n");
}

int main() {

    FILE *fp;
    fp = fopen("input_2", "r");
    unsigned i, j;
    unsigned long long days[9] = {0};
    char buffer[MAX_LEN];
    int *v = calloc(LEN, sizeof(int));
    char *aux;
    unsigned long long nr = 0;
    unsigned long long zero;
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }
    
    fgets(buffer, MAX_LEN, fp);

    // Parse input
    aux = strtok(buffer, ", \n");
    while(aux != NULL) {
        v[nr++] = atoi(aux);
        aux = strtok(NULL, ", \n");
    }

    // We will store in days array how many fish are in a status. For example
    // if we have 12 fish with status 2, then days[2] = 12.
    for(i = 0; i < nr; i++) {
        days[v[i]]++; 
    }

    for(i = 0; i < DAYS; i++) {
        zero = days[0];
        days[0] = 0;
        for(j = 1; j < 9; j++) {
            days[j-1] = days[j];
            days[j] = 0;
        }
        days[6] += zero;
        days[8] += zero;
    }

    nr = 0;
    for(i = 0; i < 9; i++) {
        nr += days[i];
    }

    fclose(fp);
    printf("%llu\n", nr);
    free(v);

    return 0;
}
