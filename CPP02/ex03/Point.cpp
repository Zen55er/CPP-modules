/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:49:45 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/08 16:38:33 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float fx, const float fy): _x(fx), _y(fy) {}

Point::Point(const Point &point_copy)
{
	*this = point_copy;
}

Point::~Point() {}

Point &Point::operator=(Point point_copy)
{
	return (point_copy);
}

Fixed Point::get_x(void) const
{
	return (this->_x);
}

Fixed Point::get_y(void) const
{
	return (this->_y);
}
