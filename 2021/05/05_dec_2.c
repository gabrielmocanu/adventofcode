#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define ROWS 1000
#define COLUMNS 1000

int get_overlapping(int matr[ROWS][COLUMNS]) {
    int res = 0, i, j;
    
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            if(matr[i][j] >= 2) {
                res++;
            }
        }
    }
    return res;
}

void print_matrix(int matr[ROWS][COLUMNS]) {
    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}


int main() {

    FILE *fp;
    char buffer[MAX_LEN];
    int x1, y1, x2, y2;
    int i, j;
    int matr[ROWS][COLUMNS] = {0};
    fp = fopen("input_2", "r");
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    while(fgets(buffer, MAX_LEN, fp)) {     
        sscanf(buffer,"%d,%d -> %d,%d\n", &x1, &y1, &x2, &y2);
        if(x1 == x2 && y1 <= y2) {
            for(i = y1; i <= y2; i++) {
                matr[i][x1]++;
            }
        } else if(x1 == x2 && y1 > y2) {
            for(i = y2; i <= y1; i++) {
                matr[i][x1]++;
            }
        } else if(y1 == y2 && x1 <= x2) {
            for(i = x1; i <= x2; i++) {
                matr[y1][i]++;
            }
        } else if(y1 == y2  && x1 > x2) {
            for(i = x2; i <= x1; i++) {
                matr[y1][i]++;
            }
        } else if(x1 < x2 && y1 < y2){
            for(i = y1, j = x1; (i <= y2 && j <= x2); i++, j++) {
                matr[i][j]++;
            }
        } else if(x1 < x2 && y1 > y2){
             for(i = y1, j = x1; (i >= y2 && j <= x2); i--, j++) {
                matr[i][j]++;
            }
        } else if(x1 > x2 && y1 < y2){
             for(i = y1, j = x1; (i <= y2 && j >= x2); i++, j--) {
                matr[i][j]++;
            }
        } else if(x1 > x2 && y1 > y2){
             for(i = y1, j=x1; (i >= y2 && j >= x2); i--, j--) {
                matr[i][j]++;
            }
        }
    }
   
    printf("%d\n", get_overlapping(matr));
    fclose(fp);

    return 0;
}
