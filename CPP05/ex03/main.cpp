/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:49:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/13 13:26:05 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	company_life(std::string name, int grade)
{
	Bureaucrat				desk_jockey(name, grade);
	ShrubberyCreationForm	ideiafix("CEO's nana's street");
	RobotomyRequestForm		express_mandatory_surgery("Head of HR");
	PresidentialPardonForm	get_out_of_jail_free("Investment manager");

	ideiafix.beSigned(desk_jockey);
	express_mandatory_surgery.beSigned(desk_jockey);
	get_out_of_jail_free.beSigned(desk_jockey);
	std::cout << std::endl;
	ideiafix.execute(desk_jockey);
	std::cout << std::endl;
	express_mandatory_surgery.execute(desk_jockey);
	std::cout << std::endl;
	get_out_of_jail_free.execute(desk_jockey);
	return (0);
}

int	error_testing(std::string name, int grade)
{
	try
	{
		company_life(name, grade);
	}
	catch(AForm::GradeTooHighException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(AForm::GradeTooLowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(AForm::FormAlreadySignedException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(AForm::FormFailExecutionException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	return (0);
}

int	main(void)
{
	error_testing("pencil_pusher", 74);
	std::cout << std::endl;
	error_testing("pencil_pusher", 10);
	std::cout << std::endl;
	error_testing("pencil_pusher", 1);
	std::cout << std::endl;
	return (0);
}
