#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define LEN 10000
#define DAYS 80

void print_array(char *array, int len) {
    int i;

    for(i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {

    FILE *fp;
    fp = fopen("input_1", "r");
    int i, j;
    char buffer[MAX_LEN];
    char *v = calloc(LEN, sizeof(char));
    char *aux;
    int nr = 0;
    int nr_added = 0;
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

    // We store in v all the fish with their status. If they have a 0
    // then we add another one at the end with status 8.
    nr_added = nr;
    for(i = 0; i < DAYS; i++) {
       for(j = 0; j < nr; j++) {
            if(v[j] == 0) {
                v[j] = 6;
                v[nr_added++] = 8;
                continue;
            }
 
            if(v[j] > 0) {
                v[j]--;
            }
        }
        nr = nr_added;
    }

    fclose(fp);
    printf("%d\n", nr);
    free(v);

    return 0;
}
