/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:39:34 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/02 10:20:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) 
{
	this->_name = name;
	std::cout << "Constructed Zombie: " << name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destroyed Zombie: " << this->_name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ...\n";
	return ;
}
