/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:49:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/08 09:54:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	bureau_life(std::string name, int grade)
{
	Bureaucrat desk_jockey(name, grade);

	std::cout << desk_jockey << std::endl;
	desk_jockey.upgrade();
	desk_jockey.upgrade();
	desk_jockey.upgrade();
	std::cout << desk_jockey << std::endl;
	desk_jockey.downgrade();
	desk_jockey.downgrade();
	desk_jockey.downgrade();
	desk_jockey.downgrade();
	std::cout << desk_jockey << std::endl;
	desk_jockey.setGrade(desk_jockey.getGrade() + 5);
	std::cout << desk_jockey << std::endl;
	desk_jockey.setGrade(desk_jockey.getGrade() - 10);
	std::cout << desk_jockey << std::endl;
	return (0);
}

int	error_testing(std::string name, int grade)
{
	try
	{
		bureau_life(name, grade);
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
	error_testing("pencil_pusher", 0);
	error_testing("pencil_pusher", 151);
	error_testing("pencil_pusher", 2);
	error_testing("pencil_pusher", 150);
	error_testing("pencil_pusher", 145);
	error_testing("pencil_pusher", 3);
	error_testing("pencil_pusher", 75);
	return (0);
}
