/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:28:07 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/28 10:43:01 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

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
		Contact();
		~Contact();
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
		void				print_contact(void);
};

#endif