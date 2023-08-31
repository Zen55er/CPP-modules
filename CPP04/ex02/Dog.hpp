/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:51:24 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/31 09:05:49 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog 	&operator=(const Dog &copy);
		void	makeSound() const;
		void	lightbulb(int i, std::string idea);
		void	ponder(int i);
};

#endif