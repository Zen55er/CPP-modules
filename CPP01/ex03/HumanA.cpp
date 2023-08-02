/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:59:01 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/02 18:31:05 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "Created HumanA, called " << name;
	std::cout << ", with weapon: " << weapon.get_type() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destroyed HumanA: " << this->_name << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.get_type();
	std::cout << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}
