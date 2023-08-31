/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 08:51:50 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/31 09:05:10 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Called Animal default constructor\n";
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "Called Animal default constructor with type " << type << std::endl;
	this->_type = type;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "Called Animal copy constructor\n";
	this->_type = copy.getType();
}

AAnimal::~AAnimal()
{
	std::cout << "Called Animal destructor\n";
}

AAnimal	&AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "Called Animal copy assignment operator\n";
	this->_type = copy.getType();
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}

/* void	AAnimal::makeSound() const
{
	std::cout << "*Muppet rock drum solo*\n";
} */
