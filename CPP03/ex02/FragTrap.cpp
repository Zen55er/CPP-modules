/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:28:10 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/14 10:07:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Called FragTrap default constructor\n";
	this->set_hit_points(100);
	this->set_energy_points(100);
	this->set_attack_damage(30);
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "Called FragTrap default constructor with name: " << name << std::endl;
	this->set_hit_points(100);
	this->set_energy_points(100);
	this->set_attack_damage(30);
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "Called FragTrap copy constructor\n";
	this->set_name(copy.get_name());
	this->set_hit_points(copy.get_hit_points());
	this->set_energy_points(copy.get_energy_points());
	this->set_attack_damage(copy.get_attack_damage());
}

FragTrap::~FragTrap()
{
	std::cout << "Called FragTrap destructor\n";
	std::cout << "Decommissioning " << this->get_name() << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "Called FragTrap copy assignment operator\n";
	this->set_name(copy.get_name());
	this->set_hit_points(copy.get_hit_points());
	this->set_energy_points(copy.get_energy_points());
	this->set_attack_damage(copy.get_attack_damage());
	return (*this);
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "Gimme five\n(Raises robotic hand with conspicuous tack)\n";
}
