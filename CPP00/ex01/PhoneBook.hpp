/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:59:27 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/28 09:36:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		current_size;
		int		index;

	public:
		PhoneBook();
		~PhoneBook();
		int		get_current_size(void);
		int		get_index(void);
		int		validate_contact(void);
		int		add_contact(void);
		int		search_contact(void);
		void	print_phonebook(void);
};

int			check_string(std::string check, int flag);
std::string	get_info(std::string field, int flag);
void		print_field(std::string info);
void		print_separator(int flag);

#endif