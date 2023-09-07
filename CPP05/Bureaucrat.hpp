/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:03:14 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/07 14:59:05 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

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
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat);