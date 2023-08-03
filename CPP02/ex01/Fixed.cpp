/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:10 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/06 09:28:35 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static	float ft_pow(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

const int	Fixed::_bits = 8;

Fixed::Fixed(void)
{
	this->_value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	// this->_value = value;
	this->_value = value * ft_pow(2, this->_bits);
	std::cout << "Constructor called (with int)\n";
}

Fixed::Fixed(const float value)
{
	// this->_value = (int)roundf(value);
	this->_value = value * ft_pow(2, this->_bits);
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

std::ostream	&operator<<(std::ostream &out, Fixed const &fp_num)
{
	return (out << fp_num.toFloat());
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

float	Fixed::toFloat(void) const
{
	return (this->_value * ft_pow(2, -this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value * ft_pow(2, -this->_bits));
}
