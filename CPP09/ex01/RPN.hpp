/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:08:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/23 15:37:10 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>

class RPN
{
	private:
		std::stack<int>	_stack;
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN 	&operator=(const RPN &copy);
		void	check_input(std::string input);
		void	parse_input(std::string input);
		void	process_input(std::string input);
		void	do_op(char op);
};
