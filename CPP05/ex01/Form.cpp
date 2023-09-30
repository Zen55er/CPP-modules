/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:49:46 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/12 09:02:40 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("generic"), _signed(false), _sign_grade(150), _execute_grade(150) {}

Form::Form(std::string name, int sign, int execute)
	: _name(name), _signed(false), _sign_grade(sign), _execute_grade(execute)
{
	if (sign > 150 || execute > 150)
		throw(GradeTooLowException());
	else if (sign < 1 || execute < 1)
		throw(GradeTooHighException());
}

Form::Form(const Form &copy)
	: _name(copy._name), _signed(false)
		, _sign_grade(copy._sign_grade), _execute_grade(copy._execute_grade) {}

Form::~Form() {}

Form &Form::operator=(const Form &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::string	Form::getName() const
{
	return (this->_name);
}

int	Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int	Form::getExecuteGrade() const
{
	return (this->_execute_grade);
}

bool	Form::isSigned() const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
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

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade is too low");
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade is too high");
}

const char	*Form::FormAlreadySignedException::what(void) const throw()
{
	return ("This form is already signed");
}

std::ostream	&operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName()
		<< ", has a sign grade of " << form.getSignGrade()
		<< " and a execution grade of " << form.getExecuteGrade()
		<< ". It is " << (form.isSigned() ? "signed" : "unsigned");
	return (out);
}
