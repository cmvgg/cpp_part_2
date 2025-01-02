NAME		:= RPN

CXX 		:= c++ -Wall -Werror -Wextra -pedantic -std=c++98

SRC_FILES	:= main RPN
SRC			:= $(addsuffix .cpp, $(SRC_FILES))
OBJ			:= $(addsuffix .o, $(SRC_FILES))

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} $^ -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re