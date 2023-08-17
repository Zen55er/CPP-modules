/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:09:49 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/17 14:37:41 by gacorrei         ###   ########.fr       */
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
		this->ideas[i] = copy.ideas[i];
	return (*this);
}
