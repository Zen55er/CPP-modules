/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:33:28 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/16 13:33:54 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat 	&operator=(const Cat &copy);
		void	makeSound() const;
};

#endif