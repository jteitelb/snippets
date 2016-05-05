CFLAGS=-std=c99 -g

decoder: decoder.c
kin: kin.c
path: path.c

clean:
	rm -f decoder
	rm -f kin
	rm -f path
