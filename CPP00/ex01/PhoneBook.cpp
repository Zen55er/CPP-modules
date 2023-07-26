/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:04:27 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/26 14:57:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	strncmp(std::string str1, std::string str2)
{
	int	i = 0;

	for ( ; str1[i]; i++)
		if (str1[i] != str2[i])
			break;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	strlen(std::string str)
{
	int	i = 0;

	for ( ; str[i]; i++)
		continue;
	return (i);
}

int	check_string(const std::string check)
{
	int	i;

	if (check.empty())
		return (1);
	for(i = 0; check[i]; i++)
		if (!std::isalpha(check[i]))
			return (1);
	if (i == 0)
		return (1);
	return (0);
}

int	check_number(const std::string check)
{
	int i;

	if (check.empty())
		return (1);
	for(i = 0; check[i]; i++)
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
		std::cout << info;
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

void	print_separator(int flag)
{
	if (flag)
		std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << std::endl;
	return;
}

void	print_contact(Contact contact, int index)
{
	print_separator(0);
	print_separator(1);
	std::cout << "|";
	std::cout << "         ";
	std::cout << index;
	std::cout << "|";
	print_column(contact.get_first_name());
	std::cout << "|";
	print_column(contact.get_last_name());
	std::cout << "|";
	print_column(contact.get_nickname());
	std::cout << "|\n";
	print_separator(0);
}

int		PhoneBook::get_current_size(void) const
{
	return (this->current_size);
}

int		PhoneBook::get_index(void) const
{
	return (this->index);
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
		std::cout << "Input contact's first name: ";
		std::cin >> first_name;
	}
	while (check_string(last_name))
	{
		std::cout << "Input contact's last name: ";
		std::cin >> last_name;		
	}
	while (check_string(nickname))
	{
		std::cout << "Input contact's nickname: ";
		std::cin >> nickname;		
	}
	while (check_number(phone_number))
	{
		std::cout << "Input contact's phone number: ";
		std::cin >> phone_number;		
	}
	while (check_string(darkest_secret))
	{
		std::cout << "Input contact's darkest secret: ";
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
	
	for (int i = 0; i < this->get_current_size(); i++)
		print_contact(this->contacts[i], i);
	std::cout << "Choose index to display: ";
	std::cin >> index;
	if (std::cin.eof())
	{
		std::cin.clear();
		return;
	}
	std::cout << std::endl;
	if (std::cin.fail() || index < 0 || index >= this->get_current_size())
	{
		std::cout << "Input an index in range [0 - " << this->get_current_size() - 1 <<"]\n";
		// std::cin.clear();
		return;
	}
	else if (index > get_current_size() - 1)
		std::cout << "There is no contact for selected index\n";
	std::cout << "First Name: " << contacts[index].get_first_name() << std::endl ;
	std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl ;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl ;
	std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl ;
	std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl ;
	return;
}

int	main(void)
{
	std::string input;
	PhoneBook	phonebook;

	//Tests for what is in phonebook at start
	std::cout << "Phonebook size is: " << phonebook.get_current_size() << std::endl;
	std::cout << "Phonebook index is: " << phonebook.get_index() << std::endl;
	std::cout << std::endl;
	while (1)
	{
		std::cout << "PhoneBook:\nChoose one: [ADD] [SEARCH] [EXIT]\n>";
		std::cin >> input;
		if (input.empty())
			break ;
		if (!strncmp(input, "ADD"))
			phonebook.add_contact();
		else if (!strncmp(input, "SEARCH"))
			phonebook.search_contact();
		else if (!strncmp(input, "EXIT"))
			break;
		input.clear();
		std::cout << std::endl;
	}
}