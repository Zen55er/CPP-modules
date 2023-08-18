/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 08:51:50 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 11:53:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Called Animal default constructor\n";
}

Animal::Animal(std::string type)
{
	std::cout << "Called Animal default constructor with type " << type << std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Called Animal copy constructor\n";
	this->_type = copy.getType();
}

Animal::~Animal()
{
	std::cout << "Called Animal destructor\n";
}

Animal	&Animal::operator=(const Animal &copy)
{
	std::cout << "Called Animal copy assignment operator\n";
	this->_type = copy.getType();
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->_type);
}

/* void	Animal::makeSound() const
{
	std::cout << "*Muppet rock drum solo*\n";
} */
