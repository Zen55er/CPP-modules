/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:32:31 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/03 14:43:18 by gacorrei         ###   ########.fr       */
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

void	ScalarConverter::converter(std::string input)
{
	int	type = check_input(input);
}

int	ScalarConverter::check_input(std::string input)
{
	int	type;
	int	pseudo = pseudo_literals(input);
	int	i = (input[0] == '+' || input[0] == '-') ? 0 : -1;
	int	i_len = input.length();
	int	len = (input[0] == '+' || input[0] == '-') ? i_len - 1 : i_len;

	if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
		return 1;
	if (!test_int(input, i, i_len, len))
		return 2;
	if (pseudo > 2 || !test_float(input, i, i_len, len))
		return 3;
	if ((pseudo > 0 && pseudo < 3) || !test_double(input, i, i_len, len))
		return 4;
	return 0;
}

int	ScalarConverter::test_int(std::string input)
{
	int	i = (input[0] == '+' || input[0] == '-') ? 0 : -1;
	int	i_len = input.length();
	int	len = (input[0] == '+' || input[0] == '-') ? i_len - 1 : i_len;

	while (++i < i_len)
		if (!isdigit(input[i]))
			return 1;
	return 0;
}

int	ScalarConverter::test_float(std::string input)
{
	int	i = (input[0] == '+' || input[0] == '-') ? 0 : -1;
	int	i_len = input.length();
	int	len = (input[0] == '+' || input[0] == '-') ? i_len - 1 : i_len;
	int	dot = 0;

	while (++i < i_len)
	{
		if (!isdigit(input[i]))
		{
			if (input[i] == '.')
			{
				if (dot)
					return 1;
				dot = 1;
			}
			else if (input[i] == 'f' && i == i_len - 1)
				break;
			return 1;
		}
	}
	return 0;
}

int	ScalarConverter::test_double(std::string input)
{
	int	i = (input[0] == '+' || input[0] == '-') ? 0 : -1;
	int	i_len = input.length();
	int	len = (input[0] == '+' || input[0] == '-') ? i_len - 1 : i_len;
	int	dot = 0;

	while (++i < i_len)
	{
		if (!isdigit(input[i]))
		{
			if (input[i] == '.')
			{
				if (dot)
					return 1;
				dot = 1;
				continue;
			}
			return 1;
		}
	}
	return 0;
}

int	ScalarConverter::pseudo_literals(std::string input)
{
	std::string	pseudo[6] = {"inf", "-inf", "nan", "inff", "-inff", "nanf"};

	for (int i = 0; i < 6; i++)
		if (pseudo[i] == input)
			return i;
	return -1;
}

int	ScalarConverter::char_converter(std::string input)
{
	if (input.length() != 1)
		std::cout << "char: impossible\n";
	else if (!isprint(input[0]))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
}

int	ScalarConverter::int_converter(std::string input)
{
	int			flag = 0;
	int			len = int_len(input);
	long long	check = std::atoll(input.c_str());

	if (!len || len > 10 || check > INT32_MAX || check < INT32_MIN)
		std::cout << "int: impossible\n";
	else
	{
		std::cout << "int: ";
		for (int i = 1; i < len; i++)
			std::cout << static_cast<int>(input[i]);
		std::cout << std::endl;
	}
}

int	ScalarConverter::float_converter(std::string input)
{

}

int	ScalarConverter::double_converter(std::string input)
{

}

int	ScalarConverter::int_len(std::string input)
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
