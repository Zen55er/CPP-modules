/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:32:31 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/04 10:09:19 by gacorrei         ###   ########.fr       */
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

	switch (type)
	{
		case 0:
			printer(0, 0, 0, 0, 1);
		case 1:
			print_char(input);
		case 2:
			print_int(input);
		case 3:
			print_float(input, 0);
		case 4:
			print_float(input, 1);
		case 5:
			print_double(input, 0);
		case 6:
			print_double(input, 1);
	}
}

int	ScalarConverter::check_input(std::string input)
{
	int	pseudo = pseudo_literals(input);
	int	i = (input[0] == '+' || input[0] == '-') ? 0 : -1;
	int	i_len = input.length();
	int	len = (input[0] == '+' || input[0] == '-') ? i_len - 1 : i_len;

	if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
		return 1;
	if (!test_int(input, i, i_len, len))
		return 2;
	if (!test_float(input, i, i_len, len))
		return 3;
	if (pseudo > 2)
		return 4;
	if (!test_double(input, i, i_len, len))
		return 5;
	if (pseudo > 0 && pseudo < 3)
		return 6;
	return 0;
}

int	ScalarConverter::test_int(std::string input, int i, int i_len, int len)
{
	while (++i < i_len)
		if (!isdigit(input[i]))
			return 1;
	return 0;
}

int	ScalarConverter::test_float(std::string input, int i, int i_len, int len)
{
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

int	ScalarConverter::test_double(std::string input, int i, int i_len, int len)
{
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

int	ScalarConverter::print_char(std::string input)
{
	char	c = input[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	printer(c, i, f, d, 0);
}

int	ScalarConverter::print_int(std::string input)
{
	if (int_tester(input))
		return 1;
	int		i = atoi(input.c_str());
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	printer(c, i, f, d, 0);
}

int	ScalarConverter::int_tester(std::string input)
{
	int			flag = 0;
	int			len = int_len(input);
	long long	check = std::atoll(input.c_str());

	if (len > 10 || check > INT32_MAX || check < INT32_MIN)
	{
		std::cout << "char: " << "Impossible\n";
		std::cout << "int: " << "Impossible\n";
		std::cout << "float: " << "Impossible\n";
		std::cout << "double: " << "Impossible\n";
		return 1;
	}
	return 0;
}

int	ScalarConverter::print_float(std::string input, int flag)
{
	if (flag)
	{
		//PSEUDO CASE
		std::cout << "char: " << "Impossible\n";
		std::cout << "int: " << "Impossible\n";
		std::cout << "float: " << "Impossible\n";
		std::cout << "double: " << "Impossible\n";
		return 0;
	}

	float	f = strtof(input.c_str(), NULL);

	if (f == HUGE_VALF || f == -HUGE_VALF)
	{
		//OVERFLOW CASE
		//INCLUDE POSSIBLE DOUBLE CONVERSION?
		printer(0, 0, 0, 0, 1);
		return 1;
	}
	
	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);

	printer(c, i, f, d, 0);
}

int	ScalarConverter::print_double(std::string input, int flag)
{
	if (flag)
	{
		//PSEUDO CASE
		return 0;
	}

	double	d = strtod(input.c_str(), NULL);

	if (d == HUGE_VAL || d == -HUGE_VAL)
	{
		//OVERFLOW CASE
		printer(0, 0, 0, 0, 1);
		return 1;
	}

	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	printer(c, i, f, d, 0);
}

int	ScalarConverter::int_len(std::string input)
{
	int	counter = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (!i && (input[i] == '+' || input[i] == '-'))
			continue;
		counter++;
	}
	return counter;
}

void	ScalarConverter::printer(char c, int i, float f, double d, int flag)
{
	if (flag)
	{
		std::cout << "char: " << "Impossible\n";
		std::cout << "int: " << "Impossible\n";
		std::cout << "float: " << "Impossible\n";
		std::cout << "double: " << "Impossible\n";
		return;
	}
	if (!isprint(c))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}
