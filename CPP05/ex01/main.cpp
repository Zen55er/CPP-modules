/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:49:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/11 15:48:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	bureau_life(std::string name, int grade, std::string name2, int grade2)
{
	Bureaucrat	desk_jockey(name, grade);
	Form		paperwork(name2, grade2, 75);

	
	return (0);
}

int	error_testing(std::string name, int grade, std::string name2, int grade2)
{
	try
	{
		bureau_life(name, grade, name2, grade2);
	}
	catch(Form::GradeTooHighException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Form::GradeTooLowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Form::FormAlreadySignedException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	return (0);
}

int	main(void)
{
	error_testing("pencil_pusher", 75, "form1", 70);
	return (0);
}
