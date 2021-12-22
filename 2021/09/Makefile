CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 09_dec_1 09_dec_2

09_dec_1: 09_dec_1.o
	$(CC) $(CFLAGS) $^ -o $@

09_dec_1.o: 09_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

09_dec_2: 09_dec_2.o
	$(CC) $(CFLAGS) $^ -o $@

09_dec_2.o: 09_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./09_dec_1

run-2:
	./09_dec_2

clean:
	rm *.o 09_dec_1 09_dec_2
