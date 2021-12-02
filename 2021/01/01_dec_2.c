#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256


int sum_three(int a, int b, int c) {
    return a + b + c;
}

int main() {

    
    int nr = 0, i = 0;
    FILE *fp;
    char buffer[1000];
    int v[2000];
    int len;
    fp = fopen("input_2", "r");
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    while(fgets(buffer, MAX_LEN, fp)) {
        buffer[strlen(buffer) - 1] = '\0';
        v[i] = atoi(buffer);
        i++;
    }
    len = i;

    for(i = 0; i < len - 3; i++) { 
        if(sum_three(v[i], v[i+1], v[i+2]) < sum_three(v[i+1], v[i+2], v[i+3])) {
            nr++;
        }
    }

    printf("%d\n", nr);
    fclose(fp);

    return 0;
}
