/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:12:21 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/23 12:45:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;
class ICharacter
{
	public:
		virtual 	~ICharacter() {}
		virtual 	std::string const &getName() const = 0;
		virtual 	void equip(AMateria *m) = 0;
		virtual 	void unequip(int idx) = 0;
		virtual 	void use(int idx, ICharacter &target) = 0;
};

#endif