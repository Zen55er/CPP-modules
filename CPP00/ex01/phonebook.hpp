/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:27 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/24 16:28:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		void				set_first_name(std::string first_name);
		void				set_last_name(std::string last_name);
		void				set_nickname(std::string nickname);
		void				set_phone_number(std::string phone_number);
		void				set_darkest_secret(std::string darkest_secret);
		const std::string	get_first_name(void) const;
		const std::string	get_last_name(void) const;
		const std::string	get_nickname(void) const;
		const std::string	get_phone_number(void) const;
		const std::string	get_darkest_secret(void) const;
};

class PhoneBook
{
	// It has an array of contacts.
	// It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.
	// Please note that dynamic allocation is forbidden
};

#endif