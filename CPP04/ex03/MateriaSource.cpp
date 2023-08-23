/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:37:45 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/23 11:37:12 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Called MateriaSource default constructor\n";
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "Called MateriaSource copy constructor\n";
	for (int i = 0; i < 4; i++)
		this->_materias[i] = copy._materias[i]->clone();
}

MateriaSource::~MateriaSource()
{
	std::cout << "Called MateriaSource destructor\n";
	for (int i = 0; this->_materias[i]; i++)
		delete this->_materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "Called MateriaSource copy assignment operator\n";
	for (int i = 0; copy._materias[i]; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		this->_materias[i] = copy._materias[i]->clone();
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *new_materia)
{
	int	i = 0;
	
	if (!new_materia)
	{
		std::cout << "Can't learn non-existent materias\n";
		return ;
	}
	if (this->_materias[3])
	{
		std::cout << "Can't learn any more materias\n";
		return ;
	}
	while (this->_materias[i] && i < 4)
		i++;
	this->_materias[i] = new_materia;
	std::cout << "Learned new materia " << new_materia->getType() << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; this->_materias[i]; i++)
	{
		if (type == this->_materias[i]->getType())
			return (this->_materias[i]->clone());
	}
	std::cout << "No matching materia type to create\n";
	return (0);
}
