# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 15:59:10 by gacorrei          #+#    #+#              #
#    Updated: 2023/07/24 16:00:52 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook
SRC		= phonebook.cpp
CC		= @c++
CFLAGS	= -Wall -Wextra -Werror -g3 -O3 -std=c++98 -fsanitize=address,undefined

all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $(^) -o $(@)
clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean re fclean