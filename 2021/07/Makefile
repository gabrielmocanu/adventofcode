CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 07_dec_1 07_dec_2

07_dec_1: 07_dec_1.o
	$(CC) $(CFLAGS) $^ -o $@

07_dec_1.o: 07_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

07_dec_2: 07_dec_2.o
	$(CC) $(CFLAGS) $^ -o $@

07_dec_2.o: 07_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./07_dec_1

run-2:
	./07_dec_2

clean:
	rm *.o 07_dec_1 07_dec_2
