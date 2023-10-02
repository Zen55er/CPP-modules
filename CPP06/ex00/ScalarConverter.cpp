/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:32:31 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/02 11:50:56 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) 
{
	void(copy);
	return;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	void(copy);
	return (*this);
}

static void		ScalarConverter::converter(std::string input)
{
	if (char_converter(input))
		return;
	else if (int_converter(input))
		return;
	else if (float_converter(input))
		return;
	else if (double_converter(input))
		return;
}

static int		ScalarConverter::char_converter(std::string input)
{
	if (input.length() != 1 || !(input[0] >= 'a' && input[0] <= 'z')
		|| !(input[0] >= 'A' && input[0] <= 'Z'))
		return 0;
	std::cout << "char: " << static_cast<char>(input)
}

static int		ScalarConverter::int_converter(std::string input)
{

}

static int		ScalarConverter::float_converter(std::string input)
{

}

static int		ScalarConverter::double_converter(std::string input)
{

}
