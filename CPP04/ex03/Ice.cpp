/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:38:35 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/23 12:49:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Called Ice default constructor\n";
	this->_type = "ice";
}

Ice::Ice(const Ice &copy)
{
	(void)copy;
	std::cout << "Called Ice copy constructor\n";
	this->_type = "ice";
}

Ice::~Ice()
{
	std::cout << "Called Ice destructor\n";
}

Ice	&Ice::operator=(const Ice &copy)
{
	(void)copy;
	std::cout << "Called Ice copy assignment operator\n";
	this->_type = "ice";
	return (*this);
}

Ice	*Ice::clone() const
{
	Ice	*clone = new Ice();

	return (clone);
}

void Ice::use(ICharacter &target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *\n";
}
