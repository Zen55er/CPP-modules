/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:15:02 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/07 15:26:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Kissinger"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	try
	{
		if (grade > 150 || grade < 1)
			throw (1);		
	}
	catch
	{
		
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

void	Bureaucrat::upgrade()
{
	this->_grade--;
}

void	Bureaucrat::downgrade()
{
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	return (out << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade() << std::endl);
}
