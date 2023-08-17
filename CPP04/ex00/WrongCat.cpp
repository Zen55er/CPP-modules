/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:38:13 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/17 13:28:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Called WrongCat default constructor\n";
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "Called WrongCat copy constructor\n";
	this->_type = copy.getType();
}

WrongCat::~WrongCat()
{
	std::cout << "Called WrongCat destructor\n";
}

WrongCat 	&WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "Called WrongCat copy assignment operator\n";
	this->_type = copy.getType();
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << this->_type << ": woeM\n";
}