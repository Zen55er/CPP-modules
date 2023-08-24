/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:39:12 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/24 14:32:08 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	p1(1, 1);
	Point	p2(1, 10);
	Point	p3(10, 1);
	Point	p4(1, 2);

	if (bsp(p1, p2, p3, p4))
	{
		std::cout << "Point is inside triangle\n";
		return (0);		
	}
	else
	{
		std::cout << "Point is NOT inside triangle\n";
		return (1);		
	}
}