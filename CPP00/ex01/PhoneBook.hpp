/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:27 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/25 14:40:14 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		current_size;
		int		index;

	public:
		//Constructor with explicit initialization of current_size
		PhoneBook() : current_size(0), index(0) {}
		int		get_current_size(void) const;
		void	add_contact(void);
		void	search_contact(void) const;
};

int		strlen(std::string str);
int		check_string(const std::string check);
int		check_number(const std::string check);
void	print_column(std::string info);
void	print_contact(Contact contact, int index);

#endif