/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:37:45 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/19 16:43:07 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Called MateriaSource default constructor\n";
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "Called MateriaSource copy constructor\n";
}

MateriaSource::~MateriaSource()
{
	std::cout << "Called MateriaSource destructor\n";
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "Called MateriaSource copy assignment operator\n";
	for (int i = 0; i < 4; i++)
		this->_materias[i] = copy._materias[i];
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *new_materia)
{

}

AMateria	*MateriaSource::createMateria(std::string const & type)
{

}
