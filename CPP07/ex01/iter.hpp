/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:22:20 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/09 14:00:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void	func(T &position)
{
	std::cout << "array contains: " << position << std::endl;
}

template <typename T>
void	func2(T &position)
{
	std::cout << "array position x 2: " << (float)(position * 2) << std::endl;
}

template <typename T>
void	iter(const T *array, unsigned int len, void (*function)(const T &))
{
	for (unsigned int i = 0; i < len; i++)
		function(array[i]);
}

template <typename T>
void	iter(T *array, unsigned int len, void (*function)(T &))
{
	for (unsigned int i = 0; i < len; i++)
		function(array[i]);
}
