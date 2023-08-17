/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:33:58 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/17 14:38:24 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Called Cat default constructor\n";
	this->_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Called Cat copy constructor\n";
	this->_type = copy.getType();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Called Cat destructor\n";
}

Cat 	&Cat::operator=(const Cat &copy)
{
	std::cout << "Called Cat copy assignment operator\n";
	this->_type = copy.getType();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << this->_type << ": Meow\n";
}