/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:58:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/16 13:41:29 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Called Dog default constructor\n";
	this->_type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Called Dog copy constructor\n";
	this->_type = copy.getType();
}

Dog::~Dog()
{
	std::cout << "Called Dog destructor\n";
}

Dog 	&Dog::operator=(const Dog &copy)
{
	std::cout << "Called Dog copy assignment operator\n";
	this->_type = copy.getType();
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << this->_type << ": Woof\n";
}
