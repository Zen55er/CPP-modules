/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:43:01 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/03 14:44:15 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <limits>

class  ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &copy);
		static void	converter(std::string input);
		static int	check_input(std::string input);
		static int	test_int(std::string input, int i, int i_len, int len);
		static int	test_float(std::string input, int i, int i_len, int len);
		static int	test_double(std::string input, int i, int i_len, int len);
		static int	pseudo_literals(std::string input);
		static int	char_converter(std::string input);
		static int	int_converter(std::string input);
		static int	float_converter(std::string input);
		static int	double_converter(std::string input);
		static int	int_len(std::string input);
};
