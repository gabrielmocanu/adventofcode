CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 01_dec_1 01_dec_2

01_dec_1: 01_dec_1.o
	$(CC) $(CFLAGS) $^ -o $@

01_dec_1.o: 01_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

01_dec_2: 01_dec_2.o
	$(CC) $(CFLAGS) $^ -o $@

01_dec_2.o: 01_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./01_dec_1

run-2:
	./02_dec_2

clean:
	rm *.o 01_dec_1 01_dec_2
