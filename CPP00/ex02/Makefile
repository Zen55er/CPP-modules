# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 10:32:10 by gacorrei          #+#    #+#              #
#    Updated: 2023/07/31 12:21:17 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= accounts
SRC		= Account.cpp tests.cpp
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