CC := cc
CFLAGS := -Iinc
LDFLAGS := -lSDL2
NAME := game

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

C_SOURCES := 	src/Main.c \
				src/AddComponentBox.c \
				src/AddComponentKeyboard.c \
				src/AddComponentPosition.c \
				src/AddComponentRectangle.c \
				src/AddComponentSprite.c \
				src/AddComponentGravity.c \
				src/AddComponentVelocity.c \
				src/CollisionSystem.c \
				src/DrawImageSystem.c \
				src/DrawSystem.c \
				src/Entity.c \
				src/KeyboardSystem.c \
				src/MovementSystem.c \
				src/GravitySystem.c \
				src/Game.c

all: $(NAME)

C_OBJS := $(C_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(C_OBJS)
	$(CC) $(CFLAGS) -g -o $(BIN_DIR)/$@ $^ $(LDFLAGS)

clean:
	rm -rf bin/game

fclean: clean
	rm -rf $(OBJ_DIR)/*.o

re: fclean all

run:
	cd ./$(BIN_DIR)
	./$(NAME)
