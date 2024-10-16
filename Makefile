NAME = BeeBoy

SRC = $(addprefix src/, main.cpp ui.cpp)

OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

INCLUDES = -Iinclude

LIBS = -lSDL2 -lSDL2_ttf

CC = c++

CFLAGS = -Wall -Wextra -Werror -Wpedantic

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

obj/%.o: src/%.cpp
		@if [ ! -d "obj" ]; then mkdir -p obj; fi
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		rm -f $(OBJ)
		rm -rf obj/

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus
