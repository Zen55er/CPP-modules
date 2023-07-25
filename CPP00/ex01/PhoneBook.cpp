/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:04:27 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/25 12:18:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

void	print_contact(Contact contact)
{
	
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

void	PhoneBook::search_contact(int index) const
{
	if (index < 0 || index > 7)
	{
		std::cout << "Input an index in range [0 - 7]/n";
		return ;
	}
	else if (index < get_current_size() - 1)
	{
		std::cout << "There is no contact for selected index/n";
		return ;
	}
	print_contact(this->contacts[index]);
	return;
}