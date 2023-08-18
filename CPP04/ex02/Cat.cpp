/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:33:58 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 11:31:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Called Cat default constructor\n";
	this->_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Called Cat copy constructor\n";
	this->_type = copy.getType();
	this->brain = new Brain();
	*this->brain = *copy.brain;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Called Cat destructor\n";
}

Cat 	&Cat::operator=(const Cat &copy)
{
	std::cout << "Called Cat copy assignment operator\n";
	this->_type = copy.getType();
	*this->brain = *copy.brain;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << this->_type << ": Meow\n";
}

void	Cat::lightbulb(int i, std::string idea)
{
	this->brain->set_idea(i, idea);
}

void	Cat::ponder(int i)
{
	std::cout << "Thinking about " << this->brain->get_idea(i) << std::endl;
}
