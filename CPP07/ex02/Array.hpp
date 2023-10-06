/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:14:54 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/06 15:09:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_len;
	public:
		Array();
		Array(unsigned int n);
		Array(const T &copy);
		~Array();
		Array &operator=(const T &copy);
		T &operator[](unsigned int index);
		unsigned int	size(void);
};

#include "Array.tpp"
