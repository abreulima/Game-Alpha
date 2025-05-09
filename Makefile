CC := cc
CFLAGS := -lSDL2
LDFLAGS := -lSDL2
NAME := game
CSOURCES := main.c
COBJS := $(CSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(COBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run:
	./game
