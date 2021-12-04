CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 04_dec_1 04_dec_2

04_dec_1: 04_dec_1.o
	$(CC) $(CFLAGS) $^ -o $@

04_dec_1.o: 04_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

04_dec_2: 04_dec_2.o
	$(CC) $(CFLAGS) $^ -o $@

04_dec_2.o: 04_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./04_dec_1

run-2:
	./04_dec_2

clean:
	rm *.o 04_dec_1 04_dec_2
