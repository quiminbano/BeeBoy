NAME = BeeBoy

SRC = $(addprefix src/, main.cpp Cpu_registers.cpp)

OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

INCLUDES = -Iinclude

CC = c++

CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++17

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

test_registers:
		$(CC) $(CFLAGS) $(INCLUDES) src/testRegisters.cpp \
		src/Cpu_registers.cpp -o test_registers

obj/%.o: src/%.cpp
		@if [ ! -d "obj" ]; then mkdir -p obj; fi
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		rm -f $(OBJ)
		rm -rf obj/

fclean: clean
		rm -f $(NAME) test_registers

re: fclean all

.PHONY: all clean fclean bonus
