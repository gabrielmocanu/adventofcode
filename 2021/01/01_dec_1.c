#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

int main() {

    
    int nr = 0;
    int n;
    FILE *fp;
    char buffer[1000];
    fp = fopen("input_1", "r");
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    fgets(buffer, MAX_LEN, fp);
    buffer[strlen(buffer) - 1] = '\0';
    n = atoi(buffer);

    while(fgets(buffer, MAX_LEN, fp)) {
        buffer[strlen(buffer) - 1] = '\0';
        if(n < atoi(buffer)) {
            nr++;
        }
        n = atoi(buffer);
    }

    printf("%d\n", nr);
    fclose(fp);

    return 0;
}
