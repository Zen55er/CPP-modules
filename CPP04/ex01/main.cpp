/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:26:09 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 11:24:24 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		std::cout << "Subject main\n";
		const Animal* j = new Dog();
		const Animal* i = new Cat();
	
		delete j;//should not create a leak
		delete i;
	}
	{
		std::cout << "\nDeep copy and ideas\n";
		Dog	Max = Dog();
		
		std::cout << "Max ideas\n";
		Max.lightbulb(0, "Burglars");
		Max.lightbulb(1, "Food");
		Max.ponder(0);
		Max.ponder(1);
		
		Dog	Rex(Max);
		
		std::cout << "Rex copies ideas\n";
		Rex.ponder(0);
		Rex.ponder(1);
		std::cout << "Max new ideas\n";
		Max.lightbulb(0, "Sniffing");
		Max.lightbulb(1, "Sleep");
		Max.ponder(0);
		Max.ponder(1);
		std::cout << "Rex ideas\n";
		Rex.ponder(0);
		Rex.ponder(1);

		Cat	Salem = Cat();
		
		std::cout << "Salem idea\n";
		Salem.lightbulb(0, "Knocking thing off table");
		Salem.ponder(0);
		
		Cat	Sylvester;
		Sylvester = Salem;
		std::cout << "Sylvester copies idea\n";
		Sylvester.ponder(0);
		std::cout << "Sylvester new idea\n";
		Sylvester.lightbulb(0, "Tweety");
		Sylvester.ponder(0);
		std::cout << "Salem idea\n";
		Salem.ponder(0);
	}
	{
		std::cout << "\nMy main\n";
		int		i = 0;
		int		size = 2;
		Animal	*playground[size];

		for (; i < size / 2; i++)
			playground[i] = new Dog();
		for (; i < size; i++)
			playground[i] = new Cat();
		for (i = 0; i < size; i++)
			playground[i]->makeSound();
		for (i = 0; i < size; i++)
			delete playground[i];
	}
}
