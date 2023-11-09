NAME		= Bureaucrat
	
CPP			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Bureaucrat AForm PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm Intern
 
SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp  RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

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
	@$(RM) *_shrubbery
	@printf " - Executable removed.\n"

re: fclean all

.PHONY: all clean fclean re