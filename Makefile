NAME = BeeBoy

SRC = $(addprefix src/, main.cpp Cpu_registers.cpp)

OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

INCLUDES = -Iinclude

CC = c++

CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++17

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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
