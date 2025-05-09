CC := cc
CFLAGS := -lSDL2
NAME := game
CSOURCES := main.c
COBJS := $(CSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(COBJS)
	$(CC) $(CFLAGS) -o $@ $^

run:
	./game