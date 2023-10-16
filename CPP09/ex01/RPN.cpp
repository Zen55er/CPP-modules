/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/16 08:54:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &copy)
{
	this->_stack = copy._stack;
	return *this;
}

void	RPN::parse_input(std::string input)
{
	std::stringstream	in(input);

	if (in.peek() == std::stringstream::traits_type::eof())
		throw(std::runtime_error("Error: input is empty"));

	char				c;
	enum				ops
	{zero = '0', one = '1', two = '2', three = '3', four = '4', five = '5', six = '6',
	seven = '7', eight = '8', nine = '9',
	plus = '+', minus = '-', multi = '*', divi = '/'};

	while (in >> c)
	{
		switch (c)
		{
		case zero:
		case one:
		case two:
		case three:
		case four:
		case five:
		case six:
		case seven:
		case eight:
		case nine:
			_stack.push(c - '0');
			break;
		case plus:
		case minus:
		case multi:
		case divi:
			do_op(c);
			break;
		default:
			throw(std::runtime_error("Error: forbidden character"));
		}
	}
	if (_stack.size() > 1)
		throw(std::runtime_error("Error: more than 1 number in stack"));
	std::cout << _stack.top() << std::endl;
}

void	RPN::process_input(std::string input)
{
	try
	{
		parse_input(input);
	}
	catch(const std::runtime_error &error)
	{
		std::cerr << error.what() << '\n';
	}
}

void	RPN::do_op(char op)
{
	if (_stack.size() < 2)
		throw(std::runtime_error("Not enough numbers to perform operations"));

	int	first;
	int	second;

	second = _stack.top();
	_stack.pop();
	first = _stack.top();
	_stack.pop();
	switch (op)
	{
		case '+':
			_stack.push(first + second);
			break;
		case '-':
			_stack.push(first - second);
			break;
		case '*':
			_stack.push(first * second);
			break;
		case '/':
			_stack.push(first / second);
			break;
	}
}
