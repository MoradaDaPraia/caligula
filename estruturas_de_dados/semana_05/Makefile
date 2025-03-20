CC=gcc
CFLAGS=-g -std=c89 -Wall -Wextra -Wstrict-prototypes -Wvla
LDFLAGS=-lm 

all:
	$(CC) $(CFLAGS) -o test test.c stack.c $(LDFLAGS)
	$(CC) $(CFLAGS) -o delimiters delimiters.c stack.c $(LDFLAGS)
