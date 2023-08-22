/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:37:45 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/22 13:18:59 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Called MateriaSource default constructor\n";
	this->_size = 0;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "Called MateriaSource copy constructor\n";
	this->_size = copy._size;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Called MateriaSource destructor\n";
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "Called MateriaSource copy assignment operator\n";
	this->_size = copy._size;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = copy._materias[i];
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *new_materia)
{
	if (!new_materia)
	{
		std::cout << "Can't learn from non-existent materias\n";
		return ;
	}
	if (this->_size == 4)
	{
		std::cout << "Can't learn any more materias\n";
		return ;
	}
	this->_materias[this->_size % 4] = new_materia;
	this->_size++;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; this->_size && i < this->_size; i++)
	{
		if (type == this->_materias[i]->getType())
			return (this->_materias[i]->clone());
	}
	std::cout << "No matching materia type to create\n";
	return (0);
}
