/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:29:38 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 15:46:53 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Called AMateria default constructor\n";
	this->type = WHAT?????;
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "Called AMateria constructor\n";
	this->type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "Called AMateria copy constructor\n";
	//this->type = type; DOES NOT MAKE SENSE?
}

AMateria::~AMateria()
{
	std::cout << "Called AMateria destructor\n";
}
AMateria	&AMateria::operator=(const AMateria &copy)
{
	std::cout << "Called AMateria copy assignment operator\n";
	//this->type = type; DOES NOT MAKE SENSE?
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	if (this->type == "ice")
		std::cout <<  "* shoots an ice bolt at " << target.getName() << " *\n";
	else if (this->type == "ice")
		std::cout <<  "* heals " << target.getName() << "'s wounds *\n";
}
