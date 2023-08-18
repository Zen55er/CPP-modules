/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:12:21 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 15:51:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class ICharacter
{
	public:
		ICharacter();
		ICharacter(const ICharacter &copy);
		virtual ~ICharacter();
		ICharacter	&operator=(const ICharacter &copy);
		virtual 	std::string const &getName() const = 0;
		virtual 	void equip(AMateria *m) = 0;
		virtual 	void unequip(int idx) = 0;
		virtual 	void use(int idx, ICharacter &target) = 0;
};

#endif