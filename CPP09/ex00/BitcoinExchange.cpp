/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:57:05 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/13 12:46:41 by gacorrei         ###   ########.fr       */
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
	return *this;
}

void	BitcoinExchange::process(std::string input)
{
	try
	{
		fetch_db("data.csv");
		file_checker(input);
	}
	catch(const std::runtime_error &error)
	{
		std::cerr << error.what() << '\n';
	}
	
}

void	BitcoinExchange::fetch_db(std::string path)
{
	std::ifstream	input(path.c_str());
	std::string		line;

	if (!input.is_open())
		throw(std::runtime_error("Error: could not open file."));
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

void	BitcoinExchange::file_checker(std::string path)
{
	std::ifstream	input(path.c_str(), std::ifstream::in);
	std::string		line;

	if (!input.is_open())
		throw(std::runtime_error("Error: could not open file."));
	if (input.peek() == std::ifstream::traits_type::eof())
	{
		input.close();
		throw(std::runtime_error("Error: file is empty."));
	}
	getline(input, line);
	if (line != "date | value")
	{
		input.close();
		throw(std::runtime_error("Error: bad header."));
	}
	while (getline(input, line))
		line_checker(line);
}

int	BitcoinExchange::line_checker(std::string line)
{
	if (line.empty() || line.length() < 14 || line[10] != ' '
		|| line[11] != '|' || line[12] != ' ' || line[13] == ' ')
	{
		std::cout << "Error: line is empty or has wrong format => "
			<< line << std::endl;
		return 1;
	}

	std::string date = line.substr(0, 10);
	std::string value = line.substr(13, line.length() - 13);
	if (date_checker(date))
		return 1;
	float	f_value = value_checker(value);
	if (f_value == -1)
		return 1;
	display_info(date, f_value);
	return 0;
}

int	BitcoinExchange::date_checker(std::string date)
{
	struct tm	time;

	if (!strptime(date.c_str(), "%Y-%m-%d", &time))
	{
		std::cout << "Error: wrong date or wrong date format => "
			<< date << std::endl;
		return 1;
	}
	return 0;
}

float	BitcoinExchange::value_checker(std::string value)
{
	int	len = value.length();
	int	dot = 0;

	if (value[0] == '-')
	{
		std::cout << "Error: number is negative => " << value << std::endl;
		return -1;
	}
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(value[i]))
		{
			if (value[i] == '.')
			{
				if (dot)
				{
					std::cout << "Error: not a number or bad number format => "
						<< value << std::endl;
					return -1;
				}
				dot = 1;
			}
			else if (value[i] == 'f' && i < len - 1)
			{
				std::cout << "Error: not a number or bad number format => "
					<< value << std::endl;
				return -1;
			}
		}
	}

	double	test = strtod(value.c_str(), NULL);

	if (test > 1000)
	{
		std::cout << "Error: number is too large => " << value << std::endl;
		return -1;
	}
	if (test > std::numeric_limits<int>::max()
		|| test < std::numeric_limits<int>::min()
		|| test > std::numeric_limits<float>::max()
		|| test < -std::numeric_limits<float>::max())
	{
		std::cout << "Error: number will overflow => " << value << std::endl;
		return -1;
	}
	else if (test > 1000)
	{
		std::cout << "Error: number is too large => " << value << std::endl;
		return -1;
	}
	return static_cast<float>(test);
}

void	BitcoinExchange::display_info(std::string date, float value)
{
	ITERATOR	it;

	it = _table.find(date);
	if (it == _table.end())
		it = find_closest(date);
	if (it == _table.end())
	{
		std::cout << "Error: could not find closest date to " << date
			<< std::endl;
		return;
	}
	std::cout << date << " => ";
	special_print(value);
	std::cout << " = ";
	special_print(it->second * value);
	std::cout << std::endl;
	return;
}

ITERATOR	BitcoinExchange::find_closest(std::string date)
{
	R_ITERATOR	rbegin = _table.rbegin();
	R_ITERATOR	rend = _table.rend();

	for (; rbegin != rend && rbegin->first.compare(date) > 0; rbegin++)
		continue;
	if (rbegin == rend)
		return _table.end();
	return --rbegin.base();
}

void	BitcoinExchange::special_print(float value)
{
	if (value != static_cast<int>(value))
	{
		std::cout << std::fixed << std::setprecision(2);
		std::cout << value;		
		std::cout.unsetf(std::ios_base::floatfield);
	}
	else
		std::cout << static_cast<int>(value);
}
