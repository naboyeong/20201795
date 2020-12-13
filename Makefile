SRCS = bookmanage.c
TARG = bookmanage
CC = gcc
OBJS = $(SRCS:.c=.o)

all: $(TARG)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS)

clean:
	rm -f $(OBJS) $(TARG)
