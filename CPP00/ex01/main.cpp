/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 08:38:25 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/28 09:39:36 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	check_string(std::string check, int flag)
{
	if (check.empty())
		return (1);
	if (!flag)
	{
		for(int i = 0; check[i]; i++)
			if (!std::isalpha(check[i]))
				return (1);
	}
	else
	{
		for(int i = 0; check[i]; i++)
			if (!std::isdigit(check[i]))
				return (1);
	}
	return (0);
}

std::string	get_info(std::string field, int flag)
{
	std::string	input;

	while (check_string(input, flag))
	{
		std::cout << "Contact's " << field << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			input.clear();
			break;
		}
		std::cin.clear();
	}
	return (input);
}

void	print_field(std::string info)
{
	int	len;

	len = info.length();
	if (len > 10)
	{
		std::cout << std::setw(9) << info.substr(0, 9);
		std::cout << std::setw(1) << ".";
	}
	else
		std::cout << std::setw(10) << info;
	std::cout << "|";
	return;
}

void	print_separator(int flag)
{
	if (flag)
	{
		std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
		return;
	}
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
	return;
}

int	main(void)
{
	std::string input;
	PhoneBook	phonebook;

	//Tests for what is in phonebook at start
	// std::cout << "Phonebook size is: " << phonebook.get_current_size() << std::endl;
	// std::cout << "Phonebook index is: " << phonebook.get_index() << std::endl;
	// std::cout << std::endl;
	while (1)
	{
		std::cout << "PhoneBook:\nChoose one: [ADD] [SEARCH] [EXIT]\n>";
		std::getline(std::cin, input);
		std::cin.clear();
		if (input.empty())
			break;
		if (input == "ADD")
		{
			if (phonebook.add_contact())
				return (1);
		}
		else if (input ==  "SEARCH")
		{
			if (phonebook.search_contact())
				return (1);
		}
		else if (input ==  "EXIT")
			break;
		else
			std::cout << "Invalid input\n";
		std::cout << std::endl;
		if (std::cin.eof())
			return (1);
	}
	return (0);
}
