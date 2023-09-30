/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:30:13 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/11 15:09:12 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
	public:
		Form();
		Form(std::string name, int sign, int execute);
		Form(const Form &copy);
		~Form();
		Form 		&operator=(const Form &copy);
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		bool		isSigned() const;
		void		beSigned(Bureaucrat &bureaucrat);
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Form const &form);
