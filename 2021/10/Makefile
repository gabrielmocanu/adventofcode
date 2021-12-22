CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 10_dec_1 10_dec_2

10_dec_1: 10_dec_1.o stack.o
	$(CC) $(CFLAGS) $^ -o $@

10_dec_1.o: 10_dec_1.c
	$(CC) $(CFLAGS) -c $^ -o $@

10_dec_2: 10_dec_2.o stack.o
	$(CC) $(CFLAGS) $^ -o $@

10_dec_2.o: 10_dec_2.c
	$(CC) $(CFLAGS) -c $^ -o $@

stack.o: ./stack/stack.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./10_dec_1

run-2:
	./10_dec_2

clean:
	rm *.o 10_dec_1 10_dec_2
