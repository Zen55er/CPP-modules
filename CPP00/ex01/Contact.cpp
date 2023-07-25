/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:30:42 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/25 10:02:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

	void	Contact::set_first_name(std::string first_name)
	{
		this->first_name = first_name;
	}

	void	Contact::set_last_name(std::string last_name)
	{
		this->last_name = last_name;
	}

	void	Contact::set_nickname(std::string nickname)
	{
		this->nickname = nickname;
	}

	void	Contact::set_phone_number(std::string phone_number)
	{
		this->phone_number = phone_number;
	}

	void	Contact::set_darkest_secret(std::string darkest_secret)
	{
		this->darkest_secret = darkest_secret;
	}

	const std::string	Contact::get_first_name(void) const
	{
		return (this->first_name);
	}

	const std::string	Contact::get_last_name(void) const
	{
		return (this->last_name);
	}

	const std::string	Contact::get_nickname(void) const
	{
		return (this->nickname);
	}

	const std::string	Contact::get_phone_number(void) const
	{
		return (this->phone_number);
	}

	const std::string	Contact::get_darkest_secret(void) const
	{
		return (this->darkest_secret);
	}
