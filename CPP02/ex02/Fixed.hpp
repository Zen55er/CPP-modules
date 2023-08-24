/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:07 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/24 11:39:19 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &fixed_copy);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	&operator=(Fixed const &fixed_copy);
		bool	operator==(Fixed const &fixed_copy) const;
		bool	operator>=(Fixed const &fixed_copy) const;
		bool	operator<=(Fixed const &fixed_copy) const;
		bool	operator<(Fixed const &fixed_copy) const;
		bool	operator>(Fixed const &fixed_copy) const;
		bool	operator!=(Fixed const &fixed_copy) const;
		Fixed	operator+(Fixed const &fixed_copy);
		Fixed	operator-(Fixed const &fixed_copy);
		Fixed	operator*(Fixed const &fixed_copy);
		Fixed	operator/(Fixed const &fixed_copy);
		Fixed	operator++(void);
		Fixed	operator++(int dummy);
		Fixed	operator--(void);
		Fixed	operator--(int dummy);
		static Fixed		&min(Fixed &n1, Fixed &n2);
		static const Fixed	&min(Fixed const &n1, Fixed const &n2);
		static Fixed		&max(Fixed &n1, Fixed &n2);
		static const Fixed	&max(Fixed const &n1, Fixed const &n2);
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fp_num);
#endif