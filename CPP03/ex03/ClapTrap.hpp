/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:14:19 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/11 09:07:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap 		&operator=(const ClapTrap &copy);
		void 			attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		std::string		get_name(void) const;
		unsigned int	get_hit_points(void) const;
		unsigned int	get_energy_points(void) const;
		unsigned int	get_attack_damage(void) const;
		void			set_name(std::string name);
		void			set_hit_points(unsigned int hit_points);
		void			set_energy_points(unsigned int energy_points);
		void			set_attack_damage(unsigned int attack_damage);
};

#endif