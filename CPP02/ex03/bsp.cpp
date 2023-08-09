/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:59:02 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/09 13:27:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Point a, Point b, Point c)
{
	Fixed	x1(a.get_x());
	Fixed	y1(a.get_y());
	Fixed	x2(b.get_x());
	Fixed	y2(b.get_y());
	Fixed	x3(c.get_x());
	Fixed	y3(c.get_y());
	Fixed	result((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);

	if (result.toInt() < 0)
		result = ((Fixed)(result.toInt() * -1));
	return (result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	a0(area(a, b, c));
	if (!a0.toInt())
	{
		std::cout << "That's not a triangle\n";
		return (false);
	}
	Fixed	a1(area(point, a, b));
	Fixed	a2(area(point, a, c));
	Fixed	a3(area(point, b, c));
	if (!a1.toInt() || !a2.toInt() || !a3.toInt())
	{
		std::cout << "The point can't be in a vertex or edge\n";
		return (false);		
	}
	if (a0 >= (a1 + a2 + a3))
		return (true);
	return (false);
}
