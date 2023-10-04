/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:43:01 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/04 10:25:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <cmath>

class  ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);
		static int	converter(std::string input);
		static int	check_input(std::string input);
		static int	test_int(std::string input, int i, int i_len);
		static int	test_float(std::string input, int i, int i_len);
		static int	test_double(std::string input, int i, int i_len);
		static int	pseudo_literals(std::string input);
		static int	print_char(std::string input);
		static int	print_int(std::string input);
		static int	print_float(std::string input, int flag);
		static int	print_double(std::string input, int flag);
		static int	int_tester(std::string input);
		static int	int_len(std::string input);
		static int	printer(char c, int i, float f, double d, int flag);
};
