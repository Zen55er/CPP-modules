/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:15:02 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/13 11:52:13 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Kissinger"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _name(copy._name), _grade(copy._grade) {}

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
	if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
	this->_grade = grade;
}

void	Bureaucrat::upgrade()
{
	if (this->_grade <= 1)
		throw(GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::downgrade()
{
	if (this->_grade >= 150)
		throw(GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &form, bool sign)
{
	if (!sign && form.getSignGrade() >= this->_grade)
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " could not sign " << form.getName()
			<< ((!sign && form.getSignGrade() < this->_grade) ?
			" because his grade was too low" : " because it was already signed")
			<< std::endl;
	return ;
}

int	Bureaucrat::executeForm(AForm const &form) const
{
	if (form.isSigned() && form.getExecuteGrade() >= this->_grade)
	{
		std::cout << this->_name << " executed " << form.getName() << std::endl;
		return (0);
	}
	else
	{
		std::cout << this->_name << " could not execute " << form.getName()
			<< ((form.isSigned() && form.getExecuteGrade() < this->_grade) ?
			" because his grade was too low" : " because it was not signed")
			<< std::endl;
		return (1);
	}
	return (0);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat's grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat's grade is too low");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	return (out << bureaucrat.getName()
		<< ", bureaucrat grade: " << bureaucrat.getGrade());
}
