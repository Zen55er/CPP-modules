/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:55 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/16 14:32:11 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	_vec = copy._vec;
	_lst = copy._lst;
	return *this;
}

void	PmergeMe::sorter(char **input)
{
	std::cout << "Before: ";
	for (int i = 0; input[i]; i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;
	try
	{
		//DO INPUT CHECKER HERE?
		processor(input, false);
		processor(input, true);
	}
	catch(const std::runtime_error &error)
	{
		std::cerr << error.what() << '\n';
	}
}

void	PmergeMe::processor(char **input, bool type)
{
	std::pair<int, int> temp;

	for (int i = 0; input[i]; i++)
	{
		if (!type)
			input_validation(static_cast<std::string>(input[i]));
		if (i % 2)
		{
			temp = std::make_pair(atoi(input[i - 1]), atoi(input[i]));
			_vec.push_back(temp);
			_lst.push_back(temp);
		}
	}
}

int		PmergeMe::input_validation(std::string input)
{
	long				test = strtoul(input.c_str(), NULL, 0);
	std::stringstream	st(input);
	char				c;

	while (st >> c)
		if (!isdigit(c))
			throw(std::runtime_error("Error: use ONLY positive ints"));
	if ((!test && input != "0") || test < 0
		|| test > std::numeric_limits<int>::max())
		throw(std::runtime_error("Error: use ONLY positive ints"));
	return 0;
}
