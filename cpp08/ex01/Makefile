NAME    := Span

C       := c++ -Wall -Werror -Wextra -g3 -pedantic -std=c++98 -fsanitize=address

SRC_DIR := src/

OBJ_DIR := obj/

SRC_FILES := main span

SRC     := $(addprefix ${SRC_DIR}, $(addsuffix .cpp, ${SRC_FILES}))
OBJ := $(addsuffix .o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ) $(I)
	$(C) $(OBJ) -o $(NAME)

clean:
	rm -rf ${NAME}

a: all
	time ./${NAME}

fclean: clean
	rm -rf *.o

re: fclean all

.PHONY: all clean fclean re 