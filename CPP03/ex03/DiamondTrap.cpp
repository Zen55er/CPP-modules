/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:54:05 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/25 09:16:32 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "Called DiamondTrap default constructor\n";
	this->_name = "Minion";
	this->ClapTrap::_name = (std::string)"Minion" + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "Called DiamondTrap constructor with name: " << name << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "Called DiamondTrap copy constructor\n";
	this->_name = copy._name;
	this->ClapTrap::_name = copy._name + "_clap_name";
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "Called DiamondTrap copy assignment operator\n";
	this->_name = copy._name;
	this->ClapTrap::_name = copy._name + "_clap_name";
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Called DiamondTrap destructor for " << this->_name << std::endl;
}

void	DiamondTrap::attack(std::string target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << this->_name << ": My name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}
