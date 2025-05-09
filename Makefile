CC := cc
CFLAGS :=
LDFLAGS := -lSDL2
NAME := game
CSOURCES := main.c
COBJS := $(CSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(COBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

run:
	./game
