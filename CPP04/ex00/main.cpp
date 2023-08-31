/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:38:07 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/31 08:34:01 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		const WrongAnimal *wrong_meta = new WrongAnimal();
		const WrongCat *k = new WrongCat();
		
		std::cout << k->getType() << std::endl;
		wrong_meta->makeSound();
		k->makeSound();
		delete wrong_meta;
		delete k;
		std::cout << std::endl;
	}
	{
		Animal meta2;
		Dog j2;
		Cat i2;

		std::cout << meta2.getType() << std::endl;
		std::cout << j2.getType() << std::endl;
		std::cout << i2.getType() << std::endl;
		meta2.makeSound();
		i2.makeSound();
		j2.makeSound();		
	}
	return (0);
}
