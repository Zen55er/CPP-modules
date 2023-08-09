/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:12 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/09 10:07:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

/* int main( void )
{
	Fixed a(1.15f);
	Fixed b(-1.456f);
	Fixed c(1.963f);
	Fixed d(2.4f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "\nTesting comparisons\n";
	if (a > b)
		std::cout << "a is greater than b\n";
	else
		std::cout << "b is greater than a\n";
	if (a < b)
		std::cout << "a is smaller than b\n";
	else
		std::cout << "b is smaller than a\n";
	if (c != a)
		std::cout << "c is not equal to a\n";
	else
		std::cout << "c is equal to a\n";
	if (c == d)
		std::cout << "c is equal to d\n";
	else
		std::cout << "c is not equal to d\n";
	if (c >= d)
		std::cout << "c is greater than/equal to d\n";
	else
		std::cout << "c is greater than/equal to d\n";
	if (c <= d)
		std::cout << "c is smaller than/equal to d\n";
	else
		std::cout << "c is smaller than/equal to d\n";
	std::cout << "\na = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "\nTesting arithmetic\n";
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "b - c = " << b - c << std::endl;
	std::cout << "a * c = " << a * c << std::endl;
	std::cout << "c / d = " << c / d << std::endl;
	std::cout << "\na = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "\nTesting increment/decrement\n";
	std::cout << "a before post increment = " << a << std::endl;
	std::cout << "a after post increment = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b before pre increment = " << b << std::endl;
	std::cout << "b after pre increment = " << ++b << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a before post decrement = " << a << std::endl;
	std::cout << "a after post decrement = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b before pre decrement = " << b << std::endl;
	std::cout << "b after pre decrement = " << --b << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "\na = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "\nTesting min/max\n";
	std::cout << "min between a and b: " << Fixed::min(a, b) << std::endl;
	std::cout << "max between b and c: " << Fixed::max(b, c) << std::endl;
	std::cout << "max between c and d: " << Fixed::max(c, d) << std::endl;
	return (0);
} */