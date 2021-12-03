#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256
#define COLUMNS 12
#define ROWS 1000

/*
 * Struct to keep all lines from input:
 * input->bits
 * ok->correct/wrong values
 */
typedef struct Data {
    char input[COLUMNS+1];
    char ok;
} Data;

/*
 * Transorm a binary string to decimal number
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

/*
 * Print each data with status. Print for debugging purpose.
 */
void print_data(Data *data) {
    int i, j;
    
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++ ) { 
            printf("%d", data[i].input[j]);
        }
        printf(" ok: %d\n", data[i].ok);
    }
}

/*
 * Check each line if have on the column the most common bits.
 */
void check_numbers(Data *data, int column, char most_common) {
    int i;
    
    for(i = 0; i < ROWS; i++) {
        if( data[i].input[column] != most_common && data[i].ok == 1) {
            data[i].ok = 0;
        }
    }
}

/*
 * How many lines are good
 */
int available_data(Data *data) {
    int i ,nr = 0;

    for(i = 0; i < ROWS; i++) { 
        if(data[i].ok == 1) {
            nr++;
        }
    }

    return nr;
}

/*
 * Return the index with the single good data after running the algorithm.
 */
int find_available_data(Data *data) { 
    int i;

    for(i = 0; i < ROWS; i++) { 
        if(data[i].ok == 1) {
            return i;
        }
    }
    return -1;
}


int main() {

    char oxygen[COLUMNS+1] = {0};
    char co2[COLUMNS+1] = {0};
    int i,j;
    int rows = 0, freq_0 = 0;
    FILE *fp;
    Data *data = malloc(ROWS * sizeof(Data));
    char *buffer = malloc(MAX_LEN * sizeof(char));
    fp = fopen("input_2", "r");
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
            data[rows].input[j] = buffer[j] - '0';
        }
        data[rows].ok = 1;
        rows++;
    }

    /*
     * Construct data for oxygen
     */
    for(j = 0; j < COLUMNS; j++) {
        for(i = 0; i < rows; i++) {
            if(data[i].input[j] == 0 && data[i].ok == 1)
                freq_0++;
        }

        if(freq_0 > available_data(data) - freq_0) {
            check_numbers(data, j, 0); 
        } else if (freq_0 < available_data(data) - freq_0) {
            check_numbers(data, j, 1); 
        } else {
            check_numbers(data, j, 1);     
        }

        freq_0 = 0;
    }

    memcpy(oxygen, data[find_available_data(data)].input, COLUMNS);

    /*
     * Reinitilized ok variable for every line
     */ 
    for(i = 0; i < rows; i++) { 
        data[i].ok = 1;
    }

    /*
     * Construct data for CO2
     */
    for(j = 0; j < COLUMNS; j++) {

        if(available_data(data) == 1) { 
            break;
        }

        for(i = 0; i < rows; i++) {
            if(data[i].input[j] == 0 && data[i].ok == 1)
                freq_0++;
        }

        if(freq_0 < available_data(data) - freq_0) {
            check_numbers(data, j, 0); 
        } else if (freq_0 > available_data(data) - freq_0) {
            check_numbers(data, j, 1); 
        } else {
            check_numbers(data, j, 0);  
        }

        freq_0 = 0;
    }
    memcpy(co2, data[find_available_data(data)].input, COLUMNS);

    printf("oxygen: %d co2: %d\n", bin_to_dec(oxygen), bin_to_dec(co2));
    printf("oxygen * co2: %d\n", bin_to_dec(oxygen) * bin_to_dec(co2));

    fclose(fp);

    return 0;
}
