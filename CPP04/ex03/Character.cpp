/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:36:57 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 15:55:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Called Character default constructor\n";
	this->_name = "Deprived";
}

Character::Character(std::string name)
{
	std::cout << "Called Character constructor with name " << name << std::endl;
	this->_name = name;
}

Character::Character(const Character &copy)
{
	std::cout << "Called Character copy constructor\n";
	this->_name = copy.getName();
	this->_inventory MISSING FUNCTION!!!!!
}

Character::~Character()
{
	std::cout << "Called Character destructor\n";
}

Character &Character::operator=(const Character &copy)
{
	std::cout << "Called Character copy assignment operator\n";
	this->_name = copy.getName();
	this->_inventory MISSING FUNCTION!!!!!
}

std::string	const &Character::getName() const
{
	return (this->_name);
}

void		Character::equip(AMateria *m)
{
	
}

void		Character::unequip(int idx)
{
	
}

void		Character::use(int idx, ICharacter &target)
{
	
}
