/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:36:57 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/31 09:29:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Called Character default constructor\n";
	this->_name = "Deprived";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name)
{
	std::cout << "Called Character constructor with name " << name << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	std::cout << "Called Character copy constructor\n";
	this->_name = copy.getName();
	for (int i = 0; i < 4 && copy._inventory[i]; i++)
		this->_inventory[i] = copy._inventory[i]->clone();
}

Character::~Character()
{
	std::cout << "Called Character destructor for " << this->_name << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

Character &Character::operator=(const Character &copy)
{
	std::cout << "Called Character copy assignment operator\n";
	this->_name = copy.getName();
	for (int i = 0; i < 4 && copy._inventory[i]; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = copy._inventory[i]->clone();
	}
	return (*this);
}

std::string	const &Character::getName() const
{
	return (this->_name);
}

void		Character::equip(AMateria *m)
{
	int	i = 0;
	
	if (!m)
	{
		std::cout << "Non-existent materia can't be equipped\n";
		return ;
	}
	for (; i < 4; i++)
	{
		if (!this->_inventory[i])
			break ;
		if (i == 3 && this->_inventory[i])
		{
			std::cout << this->_name << "'s inventory is full. Can't equip " << m->getType() << std::endl;
			return ;	
		}
	}
	this->_inventory[i] = m;
	std::cout << this->_name << " equipped " << m->getType() << " on slot " << i << std::endl;
}

void		Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index, must be in range [0-3]\n";
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "There is nothing equipped in slot " << idx << std::endl;
		return ;
	}
	std::cout << this->_name << " unequipped " << this->_inventory[idx]->getType() << " from slot " << idx << std::endl;
	this->_inventory[idx] = NULL;
}

void		Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index, must be in range [0-3]\n";
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "There is nothing in slot " << idx << " to use\n";
		return ;
	}
	this->_inventory[idx]->use(target);
}
