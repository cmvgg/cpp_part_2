NAME    := MutantStack

C       := c++ -Wall -Werror -Wextra -g3 -pedantic -fsanitize=address -std=c++98

I       := ./MutantStack.hpp

SRC_FILES := main 

SRC     := ${$(addsuffix .cpp, ${SRC_FILES})}
OBJ := $(addsuffix .o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ) $(I)
	$(C) $(OBJ) -o $(NAME)

clean:
	rm -rf *.o

a: all
	time ./${NAME}

fclean: clean
	rm -rf ${OBJ_DIR}

re: fclean all

.PHONY: all clean fclean re 