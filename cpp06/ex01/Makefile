NAME := Serialization

C := c++ -Wall -Werror -Wextra -pedantic -fsanitize=address -g3 -std=c++98

SRC_DIR := src/
OBJ_DIR := obj/

SRC_FILES := Main Serializer Data

SRC := $(addprefix ${SRC_DIR}, $(addsuffix .cpp, ${SRC_FILES}))
OBJ := $(addprefix ${OBJ_DIR}, $(addsuffix .o, $(SRC_FILES)))

all: ${NAME}

${NAME}: ${OBJ}
	${C} ${OBJ} -o $@

${OBJ_DIR}%.o: ${SRC_DIR}%.cpp
	mkdir -p ${OBJ_DIR}
	${C} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}
	rm -rf ${OBJ_DIR}

re: fclean all
