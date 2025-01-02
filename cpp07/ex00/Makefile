NAME        := template
CXX         := c++
CXXFLAGS    := -Wall -Werror -Wextra -pedantic -std=c++11 -fsanitize=address -g3
SRC         := main.cpp
HEADERS     := whatever.hpp
OBJ         := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 