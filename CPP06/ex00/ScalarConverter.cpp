/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:32:31 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/03 09:24:25 by gacorrei         ###   ########.fr       */
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
		std::cout << "char: " << static_cast<char>(input[0]);
}

int		ScalarConverter::int_converter(std::string input)
{

}

int		ScalarConverter::float_converter(std::string input)
{

}

int		ScalarConverter::double_converter(std::string input)
{

}
