/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:54:56 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/12 15:11:17 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <ctime>
#include <map>
#include <algorithm>

#define ITERATOR std::map<std::string, float>::iterator
#define R_ITERATOR std::map<std::string, float>::reverse_iterator
class BitcoinExchange
{
	private:
		std::map<std::string, float>	_table;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		void			process(std::string input);
		void			fetch_db(std::string path);
		void			file_checker(std::string path);
		int				line_checker(std::string line);
		int				date_checker(std::string date);
		float			value_checker(std::string value);
		void			display_info(std::string date, float value);
		ITERATOR		find_closest(std::string date);
};
