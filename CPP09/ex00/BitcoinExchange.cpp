/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:57:05 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/12 12:07:35 by gacorrei         ###   ########.fr       */
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
	getline(input, line);
	while (getline(input, line))
	{
		std::istringstream	s_line(line);
		std::string			date, val;

		getline(s_line, date, ',');
		getline(s_line, val);
		_table[date] = strtof(val.c_str(), NULL);
	}
	input.close();
}

void	BitcoinExchange::input_checker(std::string path)
{
	try
	{
		file_checker(path);
	}
	catch (const std::runtime_error &error)
	{
		std::cerr << error.what();
		return;
	}
}

int	BitcoinExchange::file_checker(std::string path)
{
	std::ifstream	input(path.c_str(), std::ifstream::in);
	std::string		line;

	if (!input.is_open())
		throw(std::runtime_error("Error: could not open file.\n"));
	if (input.peek() == std::ifstream::traits_type::eof())
	{
		input.close();
		throw(std::runtime_error("Error: file is empty.\n"));
	}
	getline(input, line);
	if (line != "date | value")
	{
		input.close();
		throw(std::runtime_error("Error: bad header.\n"));
	}
	while (getline(input, line))
	{
		if (line_checker(line))
		{
			input.close();
			throw(std::runtime_error("Error: [" + line + "] bad formatting.\n"));			
		}
	}
}

int	BitcoinExchange::line_checker(std::string line)
{
	if (line.empty() || line.length() < 14 || line[10] != ' '
		|| line[11] != '|' || line[12] != ' ')
		return 1;

	std::string date = line.substr(0, 10);
	std::string value = line.substr(13, line.length() - 13);
	if (date_checker(date))
		return 1;
	float	f_value = value_checker(value);
	if (f_value == -1)
		return 1;
	//DO STUFF HERE???
}

int	BitcoinExchange::date_checker(std::string date)
{
	struct tm	time;

	if (!strptime(date.c_str(), "%Y-%m-%d", &time));
		return 1;
	return 0;
}

float	BitcoinExchange::value_checker(std::string value)
{
	int	len = value.length();
	int	dot = 0;

	if (len > 4 || value[0] == '-')
		return -1;
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(value[i]))
		{
			if (value[i] == '.')
			{
				if (dot)
					return -1;
				dot = 1;
			}
			else if (value[i] == 'f' && i < len - 1)
				return -1;
		}
	}

	double	test = strtod(value.c_str(), NULL);

	if (test > std::numeric_limits<int>::max()
		|| test < std::numeric_limits<int>::min()
		|| test > std::numeric_limits<float>::max()
		|| test < std::numeric_limits<float>::min()
		|| test > 1000)
		return -1;
	return static_cast<float>(test);
}
