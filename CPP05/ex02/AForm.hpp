/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:30:13 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/13 12:06:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	_name;
		bool		_signed;
		const int	_sign_grade;
		const int	_execute_grade;
	public:
		AForm();
		AForm(std::string name, int sign, int execute);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm 			&operator=(const AForm &copy);
		std::string		getName() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;
		bool			isSigned() const;
		void			setSigned(bool sign);
		void			beSigned(Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const & executor) const;
		virtual void	executor() const = 0;
		
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
		class FormFailExecutionException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, AForm const &form);
