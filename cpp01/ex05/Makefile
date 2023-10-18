# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 18:47:12 by abelhadj          #+#    #+#              #
#    Updated: 2023/10/16 22:40:06 by abelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Harl
	
CPP			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Harl

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Harl.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CPP) $(OBJ) -o $(NAME)
	@printf " - Executable ready.\n"

%.o: %.cpp $(HEADER)
	@$(CPP) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf " - Object files removed.\n"

fclean: clean
	@$(RM) $(NAME)
	@printf " - Executable removed.\n"

re: fclean all

.PHONY: all clean fclean re