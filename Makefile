CFLAGS=-Wall -g
SRC :=${wildcard *.c}
EXE :=${SRC:.c=}

all:	main

main: $(EXE)

.c:
	gcc $< -o $@

clean:
	rm -rf *.o
	rm -rf ex?
	rm -rf ex??
	rm -rf *.dSYM

src:
	ls -lpa $(SRC)

file:
	file *