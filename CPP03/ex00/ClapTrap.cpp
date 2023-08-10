/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:33:29 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/10 08:07:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("model 0"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Called default constructor\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Called default constructor with name " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Called copy constructor\n";
	this->_name = copy.get_name();
	this->_hit_points = copy.get_hit_points();
	this->_energy_points = copy.get_energy_points();
	this->_attack_damage = copy.get_attack_damage();
}

ClapTrap::~ClapTrap()
{
	std::cout << "Called destructor for " << this->_name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Called copy assignment operator\n";
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
	std::cout << this->_name << " took " << amount << " points of damage\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy_points)
	{
		std::cout << this->get_name() <<  " has no energy points, can't repair\n";
		return ;
	}
	if (!this->_hit_points)
	{
		std::cout << this->get_name() <<  " has no hit points, can't repair\n";
		return ;
	}
	if (this->_hit_points == 10)
	{
		std::cout << this->get_name() <<  " is already at max health\n";
		return ;
	}
	std::cout << this->_name << " repaired " << amount << " hit points\n";
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
