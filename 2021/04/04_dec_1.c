#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define ROWS 5
#define COLUMNS 5

typedef struct Ticket {
    int matr[ROWS][COLUMNS];
    int mark[ROWS][COLUMNS];
} Ticket;


void print_ticket(Ticket ticket) {
    int i,j;
    printf("Ticket numbers...\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            printf("%d ", ticket.matr[i][j]);
        }
        printf("\n");
    }

    printf("Ticket marks...\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            printf("%d ", ticket.mark[i][j]);
        }
        printf("\n");
    }
}

void print_tickets(Ticket *tickets, int ticket_nr) {
    int i;
    for(i = 0; i < ticket_nr; i++) {
        print_ticket(tickets[i]);
    }
}

int check_row(Ticket ticket, int row) {
    int i, ok = 1;
    for(i = 0; i < COLUMNS; i++) {
        if(!ticket.mark[row][i]) {
            ok = 0;
            return ok;
        }
    }
    return ok;
}

int check_column(Ticket ticket, int column) {
    int i, ok = 1;
    for(i = 0; i < ROWS; i++) {
        if(!ticket.mark[i][column]) {
            ok = 0;
            return ok;
        }
    }
    return ok;
}

int check_ticket(Ticket ticket) {
    int i, ok = 0;

    // Check rows
    for(i = 0; i < ROWS; i++) {
        ok = ok | check_row(ticket, i);
    }

     // Check columns
    for(i = 0; i < COLUMNS; i++) {
        ok = ok | check_column(ticket, i);
    }

    return ok;
}

void mark_ticket(Ticket *ticket, int random) {
    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            if(ticket->matr[i][j] == random)
                ticket->mark[i][j] = 1;
        }
    }

}

int sum_unmarked(Ticket ticket) {
    int i,j, sum = 0;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            if(ticket.mark[i][j] == 0) {
                sum += ticket.matr[i][j]; 
            }
        }
    }

    return sum;
}

int mark_check_tickets(Ticket *tickets, int ticket_nr, int random) {
    int i, score = 0;
    
    for(i = 0; i < ticket_nr; i++) {
        mark_ticket(&tickets[i], random);
        if(check_ticket(tickets[i])) {
            score = random * sum_unmarked(tickets[i]);
            return score;
        }
    }

    return -1;
}


int main() {

    FILE *fp;
    int i;
    int random[1024];
    char buffer[1024];
    int random_nr = 0, res = 0;
    int ticket_nr = 0;
    Ticket *tickets = calloc(1000, sizeof(Ticket));
    char *ptr;
    fp = fopen("input_1", "r");
    if(fp == NULL) {
        perror("Failed to open the file");
        return 1;
    }

    fgets(buffer, MAX_LEN, fp);
    ptr = strtok(buffer, ",\n");
    random[random_nr++] = atoi(ptr);
    while(ptr) {
        ptr = strtok(NULL, ",\n");
        if(ptr) {
            random[random_nr++] = atoi(ptr);
        }
    }

    ticket_nr = -1;
    while(fgets(buffer, MAX_LEN, fp)) {     
        if(!strcmp(buffer,"\n")) {
            ticket_nr++;
        }

        for(i = 0; i < ROWS; i++) {
            fgets(buffer, MAX_LEN, fp);
            sscanf(buffer,"%d %d %d %d %d", &tickets[ticket_nr].matr[i][0],
                                            &tickets[ticket_nr].matr[i][1],
                                            &tickets[ticket_nr].matr[i][2],
                                            &tickets[ticket_nr].matr[i][3],
                                            &tickets[ticket_nr].matr[i][4]);
        }
    }
    ticket_nr++;

    for(i = 0; i < random_nr; i++) {
        res = mark_check_tickets(tickets, ticket_nr, random[i]);
        if(res != -1) {
            break;
        }
    }

    printf("%d\n", res);
    fclose(fp);

    return 0;
}
