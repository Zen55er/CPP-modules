/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:49:45 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/24 14:07:58 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float fx, const float fy): _x(fx), _y(fy) {}

Point::Point(const Point &copy): _x(copy.get_x()), _y(copy.get_y()) {}

Point::~Point(void) {}

Point &Point::operator=(Point copy)
{
	(void)copy;
	return (*this);
}

Fixed Point::get_x(void) const
{
	return (this->_x);
}

Fixed Point::get_y(void) const
{
	return (this->_y);
}
