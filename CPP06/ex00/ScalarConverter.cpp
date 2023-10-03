/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:32:31 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/03 12:06:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) 
{
	(void)copy;
	return;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

void		ScalarConverter::converter(std::string input)
{
	char_converter(input);
	int_converter(input);
	float_converter(input);
	double_converter(input);
}

int		ScalarConverter::char_converter(std::string input)
{
	if (input.length() != 1)
		std::cout << "char: impossible\n";
	else if (!isprint(input[0]))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
}

int		ScalarConverter::int_converter(std::string input)
{
	int			flag = 0;
	int			len = int_len(input);
	long long	check = std::atoll(input.c_str());

	if (!len || len > 10 || check > INT_MAX || check < INT_MIN)
		std::cout << "int: impossible\n";
}

int		ScalarConverter::float_converter(std::string input)
{

}

int		ScalarConverter::double_converter(std::string input)
{

}

int		ScalarConverter::int_len(std::string input)
{
	int	counter = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (!i && (input[i] == '+' || input[i] == '-'))
			continue;
		if (!isdigit(input[i]))
			break;
		else
			counter++;
	}
	return counter;
}
