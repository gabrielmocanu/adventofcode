CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 05_dec_1 05_dec_2

05_dec_1: 05_dec_1.o
	$(CC) $(CFLAGS) $^ -o $@

05_dec_1.o: 05_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

05_dec_2: 05_dec_2.o
	$(CC) $(CFLAGS) $^ -o $@

05_dec_2.o: 05_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./05_dec_1

run-2:
	./05_dec_2

clean:
	rm *.o 05_dec_1 05_dec_2
