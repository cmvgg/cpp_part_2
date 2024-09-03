NAME := ScalarConvert

C := c++ -g3 -Wall -Werror -Wextra -pedantic -std=c++98

SRC_DIR := src/
OBJ_DIR := obj/

SRC_FILES := main ScalarConvert
SRC := $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJ := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(C) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
