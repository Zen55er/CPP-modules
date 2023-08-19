/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:38:35 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/19 10:00:55 by gacorrei         ###   ########.fr       */
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
	std::cout << "Called Ice copy constructor\n";
	this->_type = copy._type;
}

Ice::~Ice()
{
	std::cout << "Called Ice destructor\n";
}

Ice	&Ice::operator=(const Ice &copy)
{
	std::cout << "Called Ice copy assignment operator\n";
	this->_type = copy._type;
	return (*this);
}

Ice	*Ice::clone() const
{
	
}

void Ice::use(ICharacter &target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *\n";
}
