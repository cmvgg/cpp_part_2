NAME := iterClass

CXX := c++ -Wall -Werror -Wextra -pedantic -std=c++98

SRC_FILES := main

SRC := $(addsuffix .cpp, $(SRC_FILES))
OBJ := $(addsuffix .o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 