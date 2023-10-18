# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 17:29:04 by abelhadj          #+#    #+#              #
#    Updated: 2023/10/16 22:40:06 by abelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
	
CPP			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= megaphone

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(OBJ) -o $(NAME)
	@printf " - Executable ready.\n"

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf " - Object files removed.\n"

fclean: clean
	@$(RM) $(NAME)
	@printf " - Executable removed.\n"

re: fclean all

.PHONY: all clean fclean re