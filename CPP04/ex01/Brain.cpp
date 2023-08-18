/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:09:49 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 09:34:04 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Called Brain default constructor\n";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Called Brain copy constructor\n";
	(*this) = copy;
}

Brain::~Brain()
{
	std::cout << "Called Brain destructor\n";
}

Brain	&Brain::operator=(const Brain &copy)
{
	std::cout << "Called Brain copy assignment operator\n";
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy.get_idea(i);
	return (*this);
}

std::string	Brain::get_idea(int index) const
{
	return (this->_ideas[index]);
}

void		Brain::set_idea(int index, std::string idea)
{
	this->_ideas[index] = idea;
}
