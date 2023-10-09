/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:33:51 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/09 09:29:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(new T[0]), _len(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _len(n) {}

template <typename T>
Array<T>::Array(const Array &copy): _array(new T[copy._len]), _len(copy._len)
{
	this->_array = new T[copy._len];
	for (int i = 0; i < _len; i++)
		_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	delete[] _array;
	_len = copy._len;
	this->_array = new T[_len];
	for (unsigned int i = 0; i < _len; i++)
		_array[i] = copy._array[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (!_len || index > _len - 1)
		throw(std::exception());
	return _array[index];
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return _len;
}
