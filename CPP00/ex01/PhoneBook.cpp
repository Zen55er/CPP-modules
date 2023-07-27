/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:04:27 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/27 15:23:19 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->current_size = 0;
	this->index  = 0;
	// std::cout << "constructed\n";
};

PhoneBook::~PhoneBook()
{
	// std::cout << "destroyed";
};

int		PhoneBook::get_current_size(void)
{
	return (this->current_size);
}

int		PhoneBook::get_index(void)
{
	return (this->index);
}

void	PhoneBook::print_phonebook(void)
{
	print_separator(0);
	print_separator(1);
	for (int i = 0; i < this->get_current_size(); i++)
	{
		print_separator(0);
		std::cout << "|" << std::setw(10) << i << "|";
		print_field(this->contacts[i].get_first_name());
		print_field(this->contacts[i].get_last_name());
		print_field(this->contacts[i].get_nickname());
		std::cout << std::endl;
		print_separator(0);	
	}
}

int	PhoneBook::validate_contact(void)
{
	if (!this->contacts[this->get_index()].get_first_name().length()
		|| !this->contacts[this->get_index()].get_last_name().length()
		|| !this->contacts[this->get_index()].get_nickname().length()
		|| !this->contacts[this->get_index()].get_phone_number().length()
		|| !this->contacts[this->get_index()].get_darkest_secret().length())
		return (1);
	return (0);
}

int	PhoneBook::add_contact(void)
{
	this->contacts[this->index].set_first_name(get_info("first name", 0));
	this->contacts[this->index].set_last_name(get_info("last name", 0));
	this->contacts[this->index].set_nickname(get_info("nick name", 0));
	this->contacts[this->index].set_phone_number(get_info("phone number", 1));
	this->contacts[this->index].set_darkest_secret(get_info("darkest secret", 0));
	if (validate_contact())
		return (1);
	this->index = (this->index + 1) % 8;
	if (this->current_size < 8)
		this->current_size++;
	return (0);
}

int	PhoneBook::search_contact(void)
{
	int			index;
	std::string	s_index;
	
	this->print_phonebook();
	std::cout << "Choose index to display: ";
	std::getline(std::cin, s_index);
	if (std::cin.eof())
		return (1);
	std::cin.clear();
	std::cout << std::endl;
	index = std::atoi(s_index.c_str());
	if (check_string(s_index, 1) || index < 0 || index >= this->get_current_size())
	{
		std::cout << "Index not in range [0 - " << this->get_current_size() - 1 << "]\n";
		return (0);
	}
	else if (index > get_current_size() - 1)
		std::cout << "There is no contact for selected index\n";
	else
		print_contact(this->contacts[index]);
	return (0);
}
