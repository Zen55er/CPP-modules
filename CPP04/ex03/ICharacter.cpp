/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:48:31 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/18 15:51:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "Called ICharacter default constructor\n";
}

ICharacter::ICharacter(const ICharacter &copy)
{
	std::cout << "Called ICharacter copy constructor\n";
}

ICharacter::~ICharacter()
{
	std::cout << "Called ICharacter destructor\n";
}

ICharacter	&ICharacter::operator=(const ICharacter &copy)
{
	std::cout << "Called ICharacter copy assignment operator\n";
}
