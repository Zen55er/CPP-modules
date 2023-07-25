/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:04:27 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/25 15:21:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	strncmp(std::string str1, std::string str2)
{
	int	i = 0;

	for (i; str1[i]; i++)
		if (str1[i] != str2[i])
			break;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	strlen(std::string str)
{
	int	i = 0;

	for (i; str[i]; i++)
		continue;
	return (i);
}

int	check_string(const std::string check)
{
	int	i;

	for(i = 0; check[i]; i++)
		if (!std::isalpha(check[i]))
			return (1);
	if (i == 0)
		return (1);
	return (0);
}

int	check_number(const std::string check)
{
	for(int i = 0; check[i]; i++)
		if (!std::isdigit(check[i]))
			return (1);
	return (0);
}

void	print_column(std::string info)
{
	int	len;
	int	align;

	len = strlen(info);
	if (len < 10)
	{
		align = 10 - len;
		for (int i = 0; i < align; i++)
			std::cout << " ";
	}
	else if (len > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << info[i];
		std::cout << ".";
	}
	else
		std::cout << info;
	return;
}

void	print_contact(Contact contact, int index)
{
	std::cout << "         ";
	std::cout << index;
	std::cout << "|";
	print_column(contact.get_first_name());
	std::cout << "|";
	print_column(contact.get_last_name());
	std::cout << "|";
	print_column(contact.get_nickname());
	std::cout << std::endl;
}

int		PhoneBook::get_current_size(void) const
{
	return (this->current_size);
}

void	PhoneBook::add_contact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while (check_string(first_name))
	{
		std::cout << "Input contact's first name\n";
		std::cin >> first_name;
	}
	while (check_string(last_name))
	{
		std::cout << "Input contact's last name\n";
		std::cin >> last_name;		
	}
	while (check_string(nickname))
	{
		std::cout << "Input contact's nickname\n";
		std::cin >> nickname;		
	}
	while (check_string(phone_number) || check_number(phone_number))
	{
		std::cout << "Input contact's phone number\n";
		std::cin >> phone_number;		
	}
	while (check_string(darkest_secret))
	{
		std::cout << "Input contact's darkest secret\n";
		std::cin >> darkest_secret;		
	}
	this->contacts[this->index].set_first_name(first_name);
	this->contacts[this->index].set_last_name(last_name);
	this->contacts[this->index].set_nickname(nickname);
	this->contacts[this->index].set_phone_number(phone_number);
	this->contacts[this->index].set_darkest_secret(darkest_secret);
	this->index = (this->index + 1) % 8;
	if (this->current_size < 8)
		this->current_size++;
}

void	PhoneBook::search_contact(void) const
{
	int	index;
	
	for (int i = 0; i < get_current_size(); i++)
		print_contact(this->contacts[i], i);
	while (1)
	{
		std::cout << "Choose index to display: ";
		std::cin >> index;
		std::cout << std::endl;
		if (index < 0 || index > 7)
			std::cout << "Input an index in range [0 - 7]\n";
		else if (index > get_current_size() - 1)
			std::cout << "There is no contact for selected index\n";
		else
			break;
	}
	print_contact(this->contacts[index], index);
	return;
}

int	main(void)
{
	std::string input;

	while (1)
	{
		std::cout << "PhoneBook: Choose one:\n[ADD]\n[SEARCH]\n[EXIT]\n";
		std::cin >> input;
		if (!strncmp(input, "ADD"))
		{
			//
			break ;
		}
		else if (!strncmp(input, "SEARCH"))
		{
			//
			break ;
		}
		else if (!strncmp(input, "EXIT"))
			break;
	}
}