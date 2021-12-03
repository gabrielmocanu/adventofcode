CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 03_dec_1 03_dec_2

03_dec_1: 03_dec_1.o
	$(CC) $(CFLAGS) $^ -o $@

03_dec_1.o: 03_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

03_dec_2: 03_dec_2.o
	$(CC) $(CFLAGS) $^ -o $@

03_dec_2.o: 03_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./03_dec_1

run-2:
	./03_dec_2

clean:
	rm *.o 03_dec_1 03_dec_2
