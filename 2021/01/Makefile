CC=gcc
CFLAGS=-Wall -Wextra -Werror

build: 01-dec 02-dec

01-dec: 01-dec.o
	$(CC) $(CFLAGS) $^ -o $@

01-dec.o: 01-dec.c
	$(CC) $(CFLAGS) -c $^ -o $@

02-dec: 02-dec.o
	$(CC) $(CFLAGS) $^ -o $@

02-dec.o: 02-dec.c
	$(CC) $(CFLAGS) -c $^ -o $@

run-1:
	./01-dec

run-2:
	./02-dec

clean:
	rm *.o 01-dec 02-dec
