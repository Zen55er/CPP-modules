# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 11:14:25 by gacorrei          #+#    #+#              #
#    Updated: 2023/08/17 14:27:32 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= polymorphism2
SRC		= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
CC		= @c++
CFLAGS	= -Wall -Wextra -Werror -Wshadow -g3 -std=c++98 -fsanitize=address,undefined

all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $(^) -o $(@)
clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean re fclean