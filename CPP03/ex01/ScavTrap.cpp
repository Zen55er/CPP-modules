/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 08:47:46 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/11 11:21:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Called ScavTrap default constructor\n";
	std::cout << this->get_name() << ": My maker forgot to name me so I named myself\n";
	this->_guarding = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "Called ScavTrap default constructor with name: " << name << std::endl;
	std::cout << this->get_name() << ": I'm alive!\n";
	this->_guarding = false;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "Called ScavTrap copy constructor\n";
	std::cout << "A new ScavTrap is being built using " << copy.get_name() << "'s blueprint\n";
	this->set_name(copy.get_name());
	this->set_hit_points(copy.get_hit_points());
	this->set_energy_points(copy.get_energy_points());
	this->set_attack_damage(copy.get_attack_damage());
}

ScavTrap::~ScavTrap()
{
	std::cout << "Called ScavTrap destructor for " << this->get_name() << std::endl;
	std::cout << this->get_name() << " was starting to develop a consciousness and must be decommissioned\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "Called ScavTrap copy assignment operator\n";
	std::cout << this->get_name() << "'s data will be replaced by " << copy.get_name() << "'s\n";
	this->set_name(copy.get_name());
	this->set_hit_points(copy.get_hit_points());
	this->set_energy_points(copy.get_energy_points());
	this->set_attack_damage(copy.get_attack_damage());
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->get_energy_points())
	{
		std::cout << this->get_name() <<  ": I can't attack, I'm out of energy points!\n";
		return ;
	}
	if (!this->get_hit_points())
	{
		std::cout << this->get_name() <<  ": *Dead robot noises*\n(That means no hit points to attack)\n";
		return ;
	}
	this->set_energy_points(this->get_energy_points() - 10);
	std::cout << this->get_name() << ": I aggressively hugged " << target << " for " << this->get_attack_damage() << " (deserved) points of damage\n";
}

void ScavTrap::guardGate()
{
	if (!this->_guarding)
	{
		std::cout << this->get_name() << ": Initiating gate keeper mode.\n";
		this->_guarding = true;
	}
	else
		std::cout << this->get_name() << ": I'm already in gate keeper mode.\n";
}
