/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:49:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/14 08:48:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	company_life(std::string name, int grade, std::string form, std::string target)
{
	Bureaucrat	desk_jockey(name, grade);
	Intern		fng;
	AForm		*new_form;

	new_form = fng.makeForm(form, target);
	new_form->beSigned(desk_jockey);
	new_form->execute(desk_jockey);
	return (0);
}

int	error_testing(std::string name, int grade, std::string form, std::string target)
{
	try
	{
		company_life(name, grade, form, target);
	}
	catch(Intern::InvalidFormNameException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch (...)
	{
		std::cerr << "Exception caught" << std::endl;
		return (1);
	}
	return (0);
}

int	main(void)
{
	error_testing("pencil_pusher", 74, "random", "the moon");
	std::cout << std::endl;
	error_testing("pencil_pusher", 10, "shrubbery creation", "parking lot");
	std::cout << std::endl;
	error_testing("pencil_pusher", 1, "ROBOTOMY REQUEST", "fng");
	std::cout << std::endl;
	error_testing("pencil_pusher", 1, "PrEsIdEnTiAl PaRdOn", "CEO");
	std::cout << std::endl;
	error_testing("pencil_pusher", 1, "robotomy creation", "everyone");
	std::cout << std::endl;
	return (0);
}
