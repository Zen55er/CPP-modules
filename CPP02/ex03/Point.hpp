/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:50:19 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/24 14:06:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		Point(const float fx, const float fy);
		Point(const Point &copy);
		~Point();
		Point &operator=(const Point copy);
		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
};

#endif