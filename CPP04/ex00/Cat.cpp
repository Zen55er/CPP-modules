/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:33:58 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/13 14:00:01 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Called Cat default constructor\n";
	this->_type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Called Cat copy constructor\n";
	this->_type = copy.getType();
}

Cat::~Cat()
{
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