/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 08:44:32 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 11:52:23 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	_type;
		Animal();
		Animal(std::string type);
	public:
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal				&operator=(const Animal &copy);
		std::string			getType() const;
		virtual void		makeSound() const = 0;
};

#endif