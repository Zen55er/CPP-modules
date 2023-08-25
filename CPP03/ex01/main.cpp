/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:19:50 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/25 08:32:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	c1;
	ScavTrap	c2("Gary");
	ScavTrap	c3(c2);
	ScavTrap	c4;

	c4 = c1;
	for (int i = 0; i < 6; i++)
	{
		c1.attack(c2.get_name());
		c2.takeDamage(c2.get_attack_damage());		
	}
	c2.beRepaired(5);
	c2.attack(c1.get_name());
	//
	c3.beRepaired(1);
	for (int i = 0; i < 6; i++)
	{
		c3.attack(c4.get_name());
		c4.takeDamage(c3.get_attack_damage());
		c4.beRepaired(c3.get_attack_damage() / 2);		
	}
	for (int i = 0; i < 44; i++)
		c3.attack("Closest wall");
	c3.beRepaired(1);
	c3.attack(c4.get_name());
	c3.guardGate();
	c3.guardGate();
	return (0);
}