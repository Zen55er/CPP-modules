/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:32:31 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/06 07:58:20 by gacorrei         ###   ########.fr       */
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

int	ScalarConverter::converter(std::string input)
{
	int	type = check_input(input);

	try
	{
		switch (type)
		{
			case 0:
				return printer(input, 0, 0, 0, 0, 1);
			case 1:
				return print_char(input);
			case 2:
				return print_int(input);
			case 3:
				return print_float(input, 0);
			case 4:
				return print_float(input, 1);
			case 5:
				return print_double(input, 0);
			case 6:
				return print_double(input, 1);
		}
	}
	catch (ScalarConverter::ConversionOverflowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	return (0);
}

int	ScalarConverter::check_input(std::string input)
{
	int	pseudo = pseudo_literals(input);
	int	i = (input[0] == '+' || input[0] == '-') ? 0 : -1;
	int	i_len = input.length();

	if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
		return 1;
	if (!test_int(input, i, i_len))
		return 2;
	if (!test_float(input, i, i_len))
		return 3;
	if (pseudo > 2)
		return 4;
	if (!test_double(input, i, i_len))
		return 5;
	if (pseudo >= 0 && pseudo < 3)
		return 6;
	return 0;
}

int	ScalarConverter::test_int(std::string input, int i, int i_len)
{
	while (++i < i_len)
		if (!isdigit(input[i]))
			return 1;
	return 0;
}

int	ScalarConverter::test_float(std::string input, int i, int i_len)
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
			else if (input[i] == 'f' && i == i_len - 1)
				break;
			return 1;
		}
	}
	return 0;
}

int	ScalarConverter::test_double(std::string input, int i, int i_len)
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

	printer(input, c, i, f, d, 0);
	return 0;
}

int	ScalarConverter::print_int(std::string input)
{
	int_tester(input);
	int		i = atoi(input.c_str());
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	printer(input, c, i, f, d, 0);
	return 0;
}

int	ScalarConverter::int_tester(std::string input)
{
	int			len = int_len(input);
	long		check = atol(input.c_str());

	if (len > 10 || check > std::numeric_limits<int>::max()
		|| check < std::numeric_limits<int>::min())
		throw(ConversionOverflowException());
	return 0;
}

int	ScalarConverter::print_float(std::string input, int flag)
{
	if (flag)
	{
		int pseudo = pseudo_literals(input);
		std::cout << "char: " << "Impossible\n";
		std::cout << "int: " << "Impossible\n";
		switch (pseudo)
		{
			case 3:
				std::cout << "float: " << "inff\n";
				std::cout << "double: " << "inf\n";
				break;
			case 4:
				std::cout << "float: " << "-inff\n";
				std::cout << "double: " << "-inf\n";
				break;
			case 5:
				std::cout << "float: " << "nanf\n";
				std::cout << "double: " << "nan\n";
		}
		return 0;
	}

	float	f = strtof(input.c_str(), NULL);

	if (f == HUGE_VALF || f == -HUGE_VALF
		|| f >= float(std::numeric_limits<int>::max())
		|| f <= float(std::numeric_limits<int>::min()))
		throw(ConversionOverflowException());
	int_tester(input);
	
	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);

	printer(input, c, i, f, d, 0);
	return 0;
}

int	ScalarConverter::print_double(std::string input, int flag)
{
	if (flag)
	{
		int pseudo = pseudo_literals(input);
		std::cout << "char: " << "Impossible\n";
		std::cout << "int: " << "Impossible\n";
		switch (pseudo)
		{
			case 0:
				std::cout << "float: " << "inff\n";
				std::cout << "double: " << "inf\n";
				break;
			case 1:
				std::cout << "float: " << "-inff\n";
				std::cout << "double: " << "-inf\n";
				break;
			case 2:
				std::cout << "float: " << "nanf\n";
				std::cout << "double: " << "nan\n";
		}
		return 0;
	}

	double	d = strtod(input.c_str(), NULL);

	if (d == HUGE_VAL || d == -HUGE_VAL
		|| d >= std::numeric_limits<int>::max()
		|| d <= std::numeric_limits<int>::min()
		|| d >= std::numeric_limits<float>::max()
		|| d <= std::numeric_limits<float>::min())
		throw(ConversionOverflowException());
	int_tester(input);

	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	printer(input, c, i, f, d, 0);
	return 0;
}

int	ScalarConverter::int_len(std::string input)
{
	int	counter = 0;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!i && (input[i] == '+' || input[i] == '-'))
			continue;
		if (!isdigit(input[i]))
			break;
		counter++;
	}
	return counter;
}

int	ScalarConverter::printer(std::string input, char c, int i, float f, double d, int flag)
{
	if (flag)
	{
		std::cout << "Can't convert " << input << std::endl;
		std::cout << "char: " << "Impossible\n";
		std::cout << "int: " << "Impossible\n";
		std::cout << "float: " << "Impossible\n";
		std::cout << "double: " << "Impossible\n";
		return 1;
	}
	if (!isprint(c))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	if (f == i)
		std::cout << "float: " << std::fixed << std::setprecision(1)
		<< f << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return 0;
}

const char	*ScalarConverter::ConversionOverflowException::what(void) const throw()
{
	return ("Attempted conversion will overflow\n");
}
