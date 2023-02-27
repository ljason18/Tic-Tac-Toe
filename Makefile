CFLAGS = -g -Wall -pedantic
CC = gcc

all : tictactoe

tictactoe: cmdline.o tictactoe.o tictactoe.h
	$(CC) $(CFLAGS) $^ -o $@  -lncurses

%: %.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f tictactoe
	rm -f *.o a.out
	rm -rf *.dSYM
