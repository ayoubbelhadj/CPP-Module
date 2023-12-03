NAME		= Serializer
	
CPP			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Serializer
 
SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Serializer.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CPP) $(OBJ) -o $(NAME)
	@echo " - Executable ready."

%.o: %.cpp $(HEADER)
	@$(CPP) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo " - Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo " - Executable removed."

re: fclean all

.PHONY: all clean fclean re