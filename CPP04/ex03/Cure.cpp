/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:01:36 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/19 10:04:23 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Called Cure default constructor\n";
	this->_type = "cure";
}

Cure::Cure(const Cure &copy)
{
	std::cout << "Called Cure copy constructor\n";
	this->_type = copy._type;
}

Cure::~Cure()
{
	std::cout << "Called Cure destructor\n";
}

Cure	&Cure::operator=(const Cure &copy)
{
	std::cout << "Called Cure copy assignment operator\n";
	this->_type = copy._type;
	return (*this);
}

Cure	*Cure::clone() const
{
	
}

void Cure::use(ICharacter &target)
{
	std::cout <<  "* heals " << target.getName() << "'s wounds *\n";
}