# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 17:08:28 by abelhadj          #+#    #+#              #
#    Updated: 2023/10/04 20:31:58 by abelhadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Sed4Loser
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Sed4Loser

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= Sed4Loser.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)
	@printf " - Executable ready.\n"

%.o: %.cpp $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf " - Object files removed.\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *.replace
	@printf " - Executable removed.\n"

re: fclean all

.PHONY: all clean fclean re