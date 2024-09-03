NAME = Bureaucrat

SRCS = Bureaucrat.cpp main.cpp AForm.cpp \
		PresidentialPardonForm.cpp RobotomyRequestForm.cpp\
		ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 