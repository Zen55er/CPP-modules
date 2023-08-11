/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:33:29 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/11 11:22:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Chatterbox"), _hit_points(100), _energy_points(50), _attack_damage(20)
{
	std::cout << "Called ClapTrap default constructor\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(100), _energy_points(50), _attack_damage(20)
{
	std::cout << "Called ClapTrap default constructor with name " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Called ClapTrap copy constructor\n";
	this->_name = copy.get_name();
	this->_hit_points = copy.get_hit_points();
	this->_energy_points = copy.get_energy_points();
	this->_attack_damage = copy.get_attack_damage();
}

ClapTrap::~ClapTrap()
{
	std::cout << "Called ClapTrap destructor for " << this->_name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Called ClapTrap copy assignment operator\n";
	this->_name = copy.get_name();
	this->_hit_points = copy.get_hit_points();
	this->_energy_points = copy.get_energy_points();
	this->_attack_damage = copy.get_attack_damage();
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->_energy_points)
	{
		std::cout << this->get_name() <<  " has no energy points, can't attack\n";
		return ;
	}
	if (!this->_hit_points)
	{
		std::cout << this->get_name() <<  " has no hit points, can't attack\n";
		return ;
	}
	this->_energy_points--;
	std::cout << this->_name << " attacked " << target << " for " << this->_attack_damage << " points of damage\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hit_points)
	{
		std::cout << "Stop! " << this->get_name() << " is already dead!\n";
		return ;
	}
	if (amount > this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << this->_name << ": I took " << amount << " points of damage\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy_points)
	{
		std::cout << this->get_name() <<  ": I can't repair myself, I'm out of energy points!\n";
		return ;
	}
	if (!this->_hit_points)
	{
		std::cout << this->get_name() <<  ": *Dead robot noises*\n(That means no hit points to repair)\n";
		return ;
	}
	if (this->_hit_points == 100)
	{
		std::cout << this->get_name() <<  ": I'm already perfect!\n";
		return ;
	}
	std::cout << this->_name << ": I repaired " << amount << " hit points\n";
	this->_energy_points--;
	this->_hit_points += amount;
}

std::string		ClapTrap::get_name(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::get_hit_points(void) const
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::get_energy_points(void) const
{
	return (this->_energy_points);
}

unsigned int	ClapTrap::get_attack_damage(void) const
{
	return (this->_attack_damage);
}

void	ClapTrap::set_name(std::string name)
{
	this->_name = name;
}

void	ClapTrap::set_hit_points(unsigned int hit_points)
{
	this->_hit_points = hit_points;
}

void	ClapTrap::set_energy_points(unsigned int energy_points)
{
	this->_energy_points = energy_points;
}

void	ClapTrap::set_attack_damage(unsigned int attack_damage)
{
	this->_attack_damage = attack_damage;
}
