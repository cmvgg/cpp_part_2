NAME        := btc

CXX         := c++ -g3 -Wall -Werror -Wextra -pedantic -std=c++98

SRC_FILES   := main BitcoinExchange

SRC := $(addsuffix .cpp, $(SRC_FILES))
OBJ := $(addsuffix .o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all