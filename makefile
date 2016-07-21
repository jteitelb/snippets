CC=gcc
CFLAGS=-std=c99 -g

all: ackermann babylonian decoder hodor kin path penney

babylonian: babylonian.c
	$(CC) $(CFLAGS) babylonian.c -lm -o babylonian 

clean:
	rm -f ackermann
	rm -f babylonian
	rm -f decoder
	rm -f hodor
	rm -f kin
	rm -f path
	rm -f penney

