#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEN 4096
#define LEN 100000

void print_array(int *array, int len) {
    int i;

    for(i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int get_max_array(int *array, int len) {
    int i, max = -1;

    for(i = 0; i < len; i++) {
        if(max < array[i]) {
            max = array[i];
        }
    }

    return max;
}

int main() {

    FILE *fp;
    fp = fopen("input_2", "r");
    int i, j;
    char buffer[MAX_LEN];
    int *v = calloc(LEN, sizeof(int));
    char *aux;
    int max = 0, min = INT_MAX, fuel_sum = 0;
    int nr = 0;
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
    max = get_max_array(v, nr);

    // For each possible position([0, max(array)]) we need to calculate
    // the minimum fuel
    for(i = 1; i <= max; i++) {
        for(j = 0; j < nr; j++) {
            fuel_sum += abs(v[j] - i);
        }
        if(min > fuel_sum) {
            min = fuel_sum;
        }
        fuel_sum = 0;
    }

    fclose(fp);
    printf("%d\n", min);
    free(v);

    return 0;
}
