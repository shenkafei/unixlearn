#makefile
CC = gcc
CFLAGS = -I ../include/ -L ../lib/ -g -Wall

SRC := $(shell find ../ -name *.c)

OBJS := $(patsubst %.c,%.o,$(SRC))

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

main : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : clean

clean:
	rm -rf $(OBJS)
	rm -f main
