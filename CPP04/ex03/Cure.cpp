/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:01:36 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/23 13:07:57 by gacorrei         ###   ########.fr       */
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
	(void)copy;
	std::cout << "Called Cure copy constructor\n";
	this->_type = "cure";
}

Cure::~Cure()
{
	std::cout << "Called Cure destructor\n";
}

Cure	&Cure::operator=(const Cure &copy)
{
	(void)copy;
	std::cout << "Called Cure copy assignment operator\n";
	this->_type = "cure";
	return (*this);
}

Cure	*Cure::clone() const
{
	Cure	*clone = new Cure();

	return (clone);
}

void Cure::use(ICharacter &target)
{
	std::cout <<  "* heals " << target.getName() << "'s wounds *\n";
}