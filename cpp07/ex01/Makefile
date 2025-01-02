NAME        := iter

CXX         := c++ -Wall -Werror -Wextra -pedantic -std=c++98 -g3

SRC_FILES   := main.cpp
OBJ_FILES   := $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 