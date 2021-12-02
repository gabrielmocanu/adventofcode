#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

int main() {

    int x = 0;
    int y = 0;
    FILE *fp;
    char buffer[1000];
    char *direction;
    char *move;
    fp = fopen("input_1", "r");
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    while(fgets(buffer, MAX_LEN, fp)) {
        buffer[strlen(buffer) - 1] = '\0';

        direction = strtok(buffer," ");
        move = strtok(NULL, " ");

        if(!strcmp(direction, "forward")) {
            x += atoi(move);
        } else if(!strcmp(direction, "down")) {
            y += atoi(move); 
        } else {
            y -= atoi(move);
        }
   }

    printf("%d\n", x*y);
    fclose(fp);

    return 0;
}
