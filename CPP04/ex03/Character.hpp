/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:23:42 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/23 12:46:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character &copy);
		~Character();
		Character 	&operator=(const Character &copy);
		std::string	const &getName() const;
		void		equip(AMateria *m);
		void		unequip(int idx);
		void		use(int idx, ICharacter &target);
};

#endif