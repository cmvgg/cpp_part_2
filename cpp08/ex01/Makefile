NAME    := Span

CXX       := c++ -Wall -Werror -Wextra -g3 -pedantic -std=c++98

SRC_FILES := main span

SRC     := $(addsuffix .cpp, ${SRC_FILES})
OBJ := $(addsuffix .o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -rf ${NAME}

fclean: clean
	rm -rf *.o

re: fclean all

.PHONY: all clean fclean re 