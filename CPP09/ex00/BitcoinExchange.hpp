/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:54:56 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/11 16:38:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_table;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		void			fetch_db(std::string path);
		int				file_checker(std::ifstream);
		int				date_checker(std::string path);
		int				value_checker(std::string path);
		int				print_error(std::string path);
};
