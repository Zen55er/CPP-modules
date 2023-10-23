# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 11:14:25 by gacorrei          #+#    #+#              #
#    Updated: 2023/10/23 15:45:06 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RPN
SRC		= main.cpp RPN.cpp
CC		= @c++
CFLAGS	= -Wall -Wextra -Werror -pedantic -Wshadow -g -std=c++98
# CFLAGS	= -Wall -Wextra -Werror -pedantic -Wshadow -g -std=c++98 -fsanitize=address,undefined
# FOR DEBUGGER TO SHOW STD::STRING
# CFLAGS	= -Wall -Wextra -Werror -pedantic -Wshadow -g -fno-limit-debug-info -std=c++98 -fsanitize=address,undefined

all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $(^) -o $(@)
clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

test: 	all
		./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
		@echo "\n-------------------\n"
		./$(NAME) "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
		@echo "\n-------------------\n"
		./$(NAME) "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
		@echo "\n-------------------\n"
		./$(NAME) "5 5 + 10 - 2 * 2 /"
		@echo "\n-------------------\n"
		./$(NAME) "5 5 + 10 - 2 * 2 / 2 +"
		@echo "\n-------------------\n"
		@echo "Empty string"
		./$(NAME) ""
		@echo "\n-------------------\n"
		@echo "Input bigger than 9"
		./$(NAME) "10 10 +"
		@echo "\n-------------------\n"
		@echo "Input with letters"
		./$(NAME) "1 2 + a +"
		@echo "\n-------------------\n"
		@echo "Input negative numbers"
		./$(NAME) "-1 -2 +"
		@echo "\n-------------------\n"
		@echo "Input with spaces"
		./$(NAME) "1 2 + "
		@echo "\n-------------------\n"
		@echo "Input simple arithmetic"
		./$(NAME) "1 2 + 3 - 4 * 5 / 6 %"
		@echo "\n-------------------\n"
		@echo "Input with only one number"
		./$(NAME) "1"
		@echo "\n-------------------\n"
		@echo "Input mix operations"
		./$(NAME) "1 2 + 3 - 4 * 5 / 6 + 9 - 3 * 1 / 4 -"
		@echo "\n-------------------\n"	
		@echo "Input multiple spaces"
		./$(NAME) "1  2        +           3     +     "
		@echo "\n-------------------\n"
		@echo "No operators"
		./$(NAME) "1 2 3 4 5 6 7 8 9"
		@echo "\n-------------------\n"
		@echo "No numbers"
		./$(NAME) "+ + + + + + + + + +"
		@echo "\n-------------------\n"
		@echo "many numbers in a row and many operators in a row"
		./$(NAME) "1 2 3 + +"
		@echo "\n-------------------\n"

	


valgrind: fclean all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

valgrind_test: fclean all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "5 5 + 10 - 2 * 2 /"
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "5 5 + 10 - 2 * 2 / 2 +"
		@echo "\n-------------------\n"
		@echo "Empty string"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ""
		@echo "\n-------------------\n"
		@echo "Input bigger than 9"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "10 10 +"
		@echo "\n-------------------\n"
		@echo "Input with letters"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1 2 + a +"
		@echo "\n-------------------\n"
		@echo "Input negative numbers"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "-1 -2 +"
		@echo "\n-------------------\n"
		@echo "Input with spaces"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1 2 + "
		@echo "\n-------------------\n"
		@echo "Input simple arithmetic"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1 2 + 3 - 4 * 5 / 6 %"
		@echo "\n-------------------\n"
		@echo "Input with only one number"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1"
		@echo "\n-------------------\n"
		@echo "Input mix operations"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1 2 + 3 - 4 * 5 / 6 + 9 - 3 * 1 / 4 -"
		@echo "\n-------------------\n"
		@echo "Input multiple spaces"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1  2        +           3     +     "
		@echo "\n-------------------\n"
		@echo "No operators"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1 2 3 4 5 6 7 8 9"
		@echo "\n-------------------\n"
		@echo "No numbers"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "+ + + + + + + + + +"
		@echo "\n-------------------\n"
		@echo "many numbers in a row and many operators in a row"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "1 2 3 + +"
		@echo "\n-------------------\n"

.PHONY:		all clean re fclean