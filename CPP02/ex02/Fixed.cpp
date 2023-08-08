/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:10 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/08 11:23:17 by gacorrei         ###   ########.fr       */
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

const int	Fixed::_bits = 8;

Fixed::Fixed(void)
{
	this->_value = 0;
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	this->_value = value * ft_pow(2, this->_bits);
	// std::cout << "Constructor called (with int)\n";
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * ft_pow(2, this->_bits));
	// std::cout << "Constructor called (with float)\n";
}

Fixed::Fixed(const Fixed &fixed_copy)
{
	// std::cout << "Copy constructor called\n";
	*this = fixed_copy;
}

Fixed &Fixed::operator=(const Fixed &fixed_copy)
{
	// std::cout << "Copy assignment operator called\n";
	this->_value = fixed_copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called\n";
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

bool	Fixed::operator==(Fixed const &fixed_copy) const
{
	return (this->getRawBits() == fixed_copy.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fixed_copy) const
{
	return (this->getRawBits() >= fixed_copy.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fixed_copy) const
{
	return (this->getRawBits() <= fixed_copy.getRawBits());
}

bool	Fixed::operator<(Fixed const &fixed_copy) const
{
	return (this->getRawBits() < fixed_copy.getRawBits());
}

bool	Fixed::operator>(Fixed const &fixed_copy) const
{
	return (this->getRawBits() > fixed_copy.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fixed_copy) const
{
	return (this->getRawBits() != fixed_copy.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &fixed_copy) const
{
	Fixed	result(this->toFloat() + fixed_copy.toFloat());

	return (result);
}

Fixed	Fixed::operator-(Fixed const &fixed_copy) const
{
	Fixed	result(this->toFloat() - fixed_copy.toFloat());

	return (result);
}

Fixed	Fixed::operator*(Fixed const &fixed_copy) const
{
	Fixed	result(this->toFloat() * fixed_copy.toFloat());

	return (result);
}

Fixed	Fixed::operator/(Fixed const &fixed_copy) const
{
	Fixed	result(this->toFloat() / fixed_copy.toFloat());

	return (result);
}

Fixed	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int dummy)
{
	Fixed	temp(*this);

	(void)dummy;
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int dummy)
{
	Fixed	temp(*this);

	(void)dummy;
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

Fixed	&Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::min(Fixed const &n1, Fixed const &n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::max(Fixed const &n1, Fixed const &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
