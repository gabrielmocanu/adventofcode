#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEN 1024

char matr[MAX_LEN][MAX_LEN];

void print_matrix(int lines, int columns) {
    int i, j;
    for(i = 0; i < lines; i++) {
        for(j = 0; j < columns; j++) {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}

int check_low_point(int x, int y, int lines, int columns)
{
    if(x > 0 && matr[x-1][y] <= matr[x][y]) return 0;
    if(y > 0 && matr[x][y-1] <= matr[x][y]) return 0;
    if(x < lines - 1 && matr[x+1][y] <= matr[x][y]) return 0;
    if(y < columns - 1 && matr[x][y+1] <= matr[x][y]) return 0;

    return 1;
}


int main() {

    FILE *fp;
    int i = 0, j = 0;
    int lines, columns;
    fp = fopen("input_2", "r");
    char buffer[MAX_LEN];
    int risk_level = 0;
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    while(fgets(buffer, MAX_LEN, fp)) {
        j = 0;
        while(buffer[j] != '\n') {
            matr[i][j] = buffer[j] - '0';
            j++;
        }
        i++;
    }
    lines = i;
    columns = j;

    for(i = 0; i < lines; i++) {
        for(j = 0;j < columns; j++) {
            if(check_low_point(i, j, lines, columns)) {
                risk_level += matr[i][j] + 1;
            }
        }
    }

    printf("Risk level is %d\n", risk_level);
    return 0;
}
