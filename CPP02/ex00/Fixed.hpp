/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:07 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/05 09:55:14 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits;
	public:
		Fixed();
		Fixed(const Fixed &fixed_copy);
		~Fixed();
		Fixed	&operator = (Fixed const &fixed_copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif