/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:35:42 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/02 18:32:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Created Weapon of type: " << type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Destroyed Weapon of type: " << this->_type << std::endl;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string &Weapon::get_type()
{
	return (this->_type);
}
