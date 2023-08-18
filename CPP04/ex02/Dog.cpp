/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:58:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 11:30:25 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Called Dog default constructor\n";
	this->_type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Called Dog copy constructor\n";
	this->_type = copy.getType();
	this->brain = new Brain();
	*this->brain = *copy.brain;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Called Dog destructor\n";
}

Dog 	&Dog::operator=(const Dog &copy)
{
	std::cout << "Called Dog copy assignment operator\n";
	this->_type = copy.getType();
	*this->brain = *copy.brain;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << this->_type << ": Woof\n";
}

void	Dog::lightbulb(int i, std::string idea)
{
	this->brain->set_idea(i, idea);
}

void	Dog::ponder(int i)
{
	std::cout << "Thinking about " << this->brain->get_idea(i) << std::endl;
}
