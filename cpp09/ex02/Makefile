NAME := PmergeMe

CXX := c++ -Wall -Werror -Wextra -pedantic -g3 -std=c++98

SRC_FILES := main PmergeMe
SRC := $(addsuffix .cpp, ${SRC_FILES})
OBJ := $(addsuffix .o, ${SRC_FILES})

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} $^ -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re