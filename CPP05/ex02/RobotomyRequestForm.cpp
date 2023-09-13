/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:54:20 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/13 12:05:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("Main street") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm("RobotomyRequestForm", 72, 45), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->_target = copy._target;
	this->setSigned(this->isSigned());
	return (*this);
}

void	RobotomyRequestForm::executor() const
{
	std::cout << "*Drilling noises*\n";
	if (std::rand() % 2)
		std::cout << this->_target << " has been successfully robotomized\n";
	else
		std::cout << this->_target << " twitched, robotomy unsuccessful\n";
	return ;
}
