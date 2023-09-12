/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:53:13 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/12 13:58:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Main street") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm("ShrubberyCreationForm", 145, 137), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->_target = copy._target;
	this->setSigned(this->isSigned());
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream out;

	if (executor.executeForm(*this))
		throw(FormFailExecutionException())
	out.open((this->_target + "_shrubbery"), std::ios::out | std::ios::trunc);
	if (!out.is_open())
	{
		std::cout << "Failed to open outfile" << std::endl;
		return ;
	}
	
	out.close();
	return ;
}
