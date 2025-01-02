NAME        := template
CXX         := c++
CXXFLAGS    := -Wall -Werror -Wextra -pedantic -std=c++11 -g3
SRC         := main.cpp
OBJ         := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 