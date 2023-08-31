/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 08:44:32 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/31 09:03:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string	_type;
		AAnimal();
		AAnimal(std::string type);
	public:
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();
		AAnimal				&operator=(const AAnimal &copy);
		std::string			getType() const;
		virtual void		makeSound() const = 0;
};

#endif