/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:13:37 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/14 08:55:40 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	return ;
}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm	*Intern::make_shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::make_robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::make_pardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm	*new_form;
	const std::string	forms[3] =
		{"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*form_func[3])(std::string target) =
		{&Intern::make_shrubbery, &Intern::make_robotomy, &Intern::make_pardon};

	for (unsigned long i = 0; i < name.length(); i++)
		name[i] = tolower(name[i]);
	for (int i = 0; i < 3; i++)
		if (name == forms[i])
			return (new_form = (this->*form_func[i])(target));
	throw(InvalidFormNameException());
	return (0);
}

const char	*Intern::InvalidFormNameException::what(void) const throw()
{
	return ("Form name is invalid");
}
