NAME := iterClass

C := c++ -Wall -Werror -Wextra -pedantic -std=c++98

SRC_FILES := main
I := ./Array.hpp

SRC := $(addsuffix .cpp, $(SRC_FILES))
OBJ := $(addsuffix .o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ) $(I)
	$(C) $(OBJ) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 