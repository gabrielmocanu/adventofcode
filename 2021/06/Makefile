CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 06_dec_1 06_dec_2

06_dec_1: 06_dec_1.o
	$(CC) $(CFLAGS) $^ -o $@

06_dec_1.o: 06_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

06_dec_2: 06_dec_2.o
	$(CC) $(CFLAGS) $^ -o $@

06_dec_2.o: 06_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./06_dec_1

run-2:
	./06_dec_2

clean:
	rm *.o 06_dec_1 06_dec_2
