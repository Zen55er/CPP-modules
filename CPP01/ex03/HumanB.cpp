/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:59:13 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/02 18:34:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = 0;
	std::cout << "Created HumanB, called " << name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "Destroyed HumanB: " << this->_name << std::endl;
}

void	HumanB::attack(void)
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " does not have a weapon to attack" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->get_type();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
