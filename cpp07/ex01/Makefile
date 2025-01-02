NAME        := iter

CXX         := c++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address -g3

SRC_FILES   := main.cpp
HEADERS     := iter.hpp
OBJ_FILES   := $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADERS)
	$(CXX) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 