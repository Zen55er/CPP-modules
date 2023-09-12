/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:49:46 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/12 13:50:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("generic"), _signed(false), _sign_grade(150), _execute_grade(150) {}

AForm::AForm(std::string name, int sign, int execute)
	: _name(name), _signed(false), _sign_grade(sign), _execute_grade(execute)
{
	if (sign > 150 || execute > 150)
		throw(GradeTooLowException());
	else if (sign < 1 || execute < 1)
		throw(GradeTooHighException());
}

AForm::AForm(const AForm &copy)
	: _name(copy._name), _signed(false)
		, _sign_grade(copy._sign_grade), _execute_grade(copy._execute_grade) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &copy)
{
	this->_name = copy._name;
	this->_signed = copy._signed;
	return (*this);
}

std::string	AForm::getName() const
{
	return (this->_name);
}

int	AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int	AForm::getExecuteGrade() const
{
	return (this->_execute_grade);
}

bool	AForm::isSigned() const
{
	return (this->_signed);
}

void	AForm::setSigned(bool sign)
{
	this->_signed = sign;
	return ;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	bureaucrat.signForm(*this, this->_signed);	
	if (this->_signed)
		throw(FormAlreadySignedException());
	else if (bureaucrat.getGrade() > this->_sign_grade)	
		throw(GradeTooLowException());
	else
		this->_signed = true;
	return ;
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade is too low");
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade is too high");
}

const char	*AForm::FormAlreadySignedException::what(void) const throw()
{
	return ("This form is already signed");
}

const char	*AForm::FormFailExecutionException::what(void) const throw()
{
	return ("This form could not be executed");
}

std::ostream	&operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName()
		<< ", has a sign grade of " << form.getSignGrade()
		<< " and a execution grade of " << form.getExecuteGrade()
		<< ". It is " << (form.isSigned() ? "signed" : "unsigned");
	return (out);
}
