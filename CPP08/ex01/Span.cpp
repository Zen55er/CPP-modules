/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:19:20 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/10 15:09:38 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _max_size(0) {}

Span::Span(unsigned int N): _max_size(N) {}

Span::Span(const Span &copy): _max_size(copy._max_size)
{
	if (copy._vec.empty())
		return;
	std::copy(copy._vec.begin(), copy._vec.end(), std::back_inserter(_vec));
}

Span::~Span()
{
	_vec.clear();
}

Span 	&Span::operator=(const Span &copy)
{
	_max_size = copy._max_size;
	if (copy._vec.empty())
		return;
	std::copy(copy._vec.begin(), copy._vec.end(), std::back_inserter(_vec));
}

void	Span::addNumber(int num)
{
	if (_vec.size() == _max_size)
		throw (MaxCapacityException());
	_vec.push_back(num);
	std::sort(_vec.begin(), _vec.end());
}

//DOUBLE CHECK HERE I WANT TO MAKE THIS TAKE ANY ITERATOR
void	Span::addRange(VEC_INT::iterator begin, VEC_INT::iterator end)
{
	if (_vec.size() == _max_size)
		throw (MaxCapacityException());
	
	std::sort(_vec.begin(), _vec.end());
}

int		Span::shortestSpan() const
{
	std::vector<int>	tmp;
	if (_vec.size() < 2)
		throw (SpanCalculationException());
	std::adjacent_difference(_vec.begin(), _vec.end(), std::back_inserter(tmp));
	return *std::min_element(tmp.begin(), tmp.end());
}

int		Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw (SpanCalculationException());
	return *std::max_element(_vec.begin(), _vec.end())
		- *std::min_element(_vec.begin(), _vec.end());
}

const char	*Span::MaxCapacityException::what() const throw()
{
	return "Max capacity reached, can't add more numbers";
}

const char	*Span::SpanCalculationException::what() const throw()
{
	return "Can't calculate span. At least 2 numbers are needed.";
}
