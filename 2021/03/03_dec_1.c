#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256
#define COLUMNS 12
#define ROWS 1000

/*
 * Transform a binary string to decimal number 
 */
int bin_to_dec(char *s) {
    
    int i, dec = 0;
    int pow = 1;

    for(i = COLUMNS - 1; i >= 0; i--) {
        if(s[i]) {
            dec += pow;
        }
        pow *= 2;
    }

    return dec;
}

int main() {

    char gamma[COLUMNS+1] = {0};
    char epsilon[COLUMNS+1] = {0};
    int i,j;
    int rows = 0, freq_0 = 0;
    FILE *fp;
    char input[ROWS][COLUMNS+1];
    char buffer[ROWS];
    fp = fopen("input_1", "r");
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    /*
     * Read all data and put all characters in input matrix
     */
    rows = 0;
    while(fgets(buffer, MAX_LEN, fp)) {
        for(j = 0; j < COLUMNS; j++) {
            input[rows][j] = buffer[j];
        }
        rows++;
    }


    /*
     * Calculate frequency of 0. If it's bigger than the frequency for 1
     * we should put in gamma 0 and in epsilon 1.
     */
    for(j = 0; j < COLUMNS; j++) {
        for(i = 0; i < rows; i++) {
            if(input[i][j] == '0')
                freq_0++;
        }

        if(freq_0 >= rows/2) {
            gamma[j] = 0;
            epsilon[j] = 1;
        } else {
            gamma[j] = 1;
            epsilon[j] = 0;
        }

        freq_0 = 0;
    }

    printf("gamma: %d epsilon: %d\n", bin_to_dec(gamma), bin_to_dec(epsilon));
    printf("gamma * epsilon: %d\n", bin_to_dec(gamma) * bin_to_dec(epsilon));


    fclose(fp);

    return 0;
}
