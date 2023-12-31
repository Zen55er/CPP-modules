/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:10 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/24 10:09:53 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static	float ft_pow(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

Fixed::Fixed(void)
{
	this->_value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	this->_value = value * ft_pow(2, this->_bits);
	std::cout << "Constructor called (with int)\n";
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * ft_pow(2, this->_bits));
	std::cout << "Constructor called (with float)\n";
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

Fixed &Fixed::operator=(const Fixed &fixed_copy)
{
	std::cout << "Copy assignment operator called\n";
	this->_value = fixed_copy.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_value / ft_pow(2, this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value / ft_pow(2, this->_bits));
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fp_num)
{
	return (out << fp_num.toFloat());
}
