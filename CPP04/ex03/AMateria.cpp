/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:29:38 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/23 11:27:58 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Called AMateria default constructor\n";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "Called AMateria constructor\n";
	this->_type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "Called AMateria copy constructor\n";
	this->_type = copy._type;
}

AMateria::~AMateria()
{
	std::cout << "Called AMateria destructor\n";
}

AMateria	&AMateria::operator=(const AMateria &copy)
{
	std::cout << "Called AMateria copy assignment operator\n";
	this->_type = copy._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << this->_type << " was used on " << target.getName();
}
