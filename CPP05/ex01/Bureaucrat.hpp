/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:03:14 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/11 14:40:14 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &copy);
		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int grade);
		void		upgrade();
		void		downgrade();
		void		signForm(Form &form, bool sign);

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
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat);