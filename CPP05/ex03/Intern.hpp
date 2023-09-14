/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:28:57 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/14 08:39:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstring>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern	&operator=(const Intern &copy);
		AForm	*makeForm(std::string name, std::string target);
		AForm	*make_shrubbery(std::string target);
		AForm	*make_robotomy(std::string target);
		AForm	*make_pardon(std::string target);
		class	InvalidFormNameException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};
