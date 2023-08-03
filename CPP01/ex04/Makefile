# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 11:14:25 by gacorrei          #+#    #+#              #
#    Updated: 2023/08/03 10:40:56 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= replace
SRC		= main.cpp replace.cpp
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