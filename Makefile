CFLAGS=-Wall

statx: statx.o

.PHONY: clean
clean:
	rm statx *.o
