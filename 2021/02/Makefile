CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 02_dec_1 02_dec_2

02_dec_1: 02_dec_1.o
	$(CC) $(CFLAGS) $^ -o $@

02_dec_1.o: 02_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

02_dec_2: 02_dec_2.o
	$(CC) $(CFLAGS) $^ -o $@

02_dec_2.o: 02_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./02_dec_1

run-2:
	./02_dec_2

clean:
	rm *.o 02_dec_1 02_dec_2
