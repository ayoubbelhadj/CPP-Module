NAME		= Bureaucrat
	
CPP			= c++
FLAGS		= #-Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Bureaucrat Form

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Bureaucrat.hpp Form.cpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CPP) $(OBJ) -o $(NAME)
	@printf " - Executable ready.\n"

%.o: %.cpp $(HEADER)
	@$(CPP) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@printf " - Object files removed.\n"

fclean: clean
	@$(RM) $(NAME)
	@printf " - Executable removed.\n"

re: fclean all

.PHONY: all clean fclean re