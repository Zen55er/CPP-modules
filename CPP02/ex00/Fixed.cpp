/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:10 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/05 10:04:53 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void)
{
	_value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed_copy)
{
	std::cout << "Copy constructor called\n";
	*this = fixed_copy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator = (const Fixed &fixed_copy)
{
	std::cout << "Copy assignment operator called\n";
	this->_value = fixed_copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
