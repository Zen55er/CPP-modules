/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:18:31 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/17 11:20:12 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Called WrongAnimal default constructor\n";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "Called WrongAnimal default constructor with type " << type << std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "Called WrongAnimal copy constructor\n";
	this->_type = copy.getType();
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Called WrongAnimal destructor\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "Called WrongAnimal copy assignment operator\n";
	this->_type = copy.getType();
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*Offkey Muppet rock drum solo*\n";
}
