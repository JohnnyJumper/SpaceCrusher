NAME = ft_retro
CC = clang++
CFLAGS = -Wall -Wextra -Werror -lncurses
DEBUG = -g

SRC_PATH = ./src/
EXE_PATH = ./bin/
INCLUDE_PATH = ./include/
OBJ_PATH = ./obj/

SRC_NAME = main.cpp Ship.cpp Bullet.cpp

SRC = $(patsubst %, $(SRC_PATH)%, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(patsubst %, $(OBJ_PATH)%, $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(DEBUG) $(OBJ) $(LDLIBS) -I$(INCLUDE_PATH)
	@mkdir -p $(EXE_PATH)
	@cp $(NAME) $(EXE_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ $(CFLAGS) -I$(INCLUDE_PATH) $(DEBUG) -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(EXE_PATH)

re: fclean all

.PHONY: clean fclean 