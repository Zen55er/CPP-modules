/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:57:05 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/11 16:38:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	_table = copy._table;
}

void	BitcoinExchange::fetch_db(std::string path)
{
	std::ifstream	input(path.c_str(), std::ifstream::in);
	std::string		line;

	if (!input.is_open())
		throw(std::runtime_error("Error: could not open file.\n"));
	if (file_checker(input));
		throw(std::runtime_error("Error: could not open file.\n"));
	getline(input, line);
	while (getline(input, line))
	{
		_table.emplace
	}
}

int	BitcoinExchange::file_checker(std::ifstream)
{

}

int	BitcoinExchange::date_checker(std::string path)
{

}

int	BitcoinExchange::value_checker(std::string path)
{

}

int	BitcoinExchange::print_error(std::string path)
{

}
