/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:19:20 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/11 10:57:51 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _max_size(0) {}

Span::Span(unsigned int N): _max_size(N) {}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span() {}

Span 	&Span::operator=(const Span &copy)
{
	_max_size = copy._max_size;
	if (copy._vec.empty())
		return *this;
	_vec = copy._vec;
	return *this;
}

void	Span::addNumber(int num)
{
	if (_vec.size() == _max_size)
		throw (MaxCapacityException());
	_vec.push_back(num);
}

void	Span::addRange(VEC_INT::iterator begin, VEC_INT::iterator end)
{
	if (_vec.size() == _max_size
		|| std::distance(begin, end) > (long)(_max_size - _vec.size()))
		throw (MaxCapacityException());
	_vec.insert(_vec.end(), begin, end);
}

long	Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw (SpanCalculationException());
	std::vector<long>	tmp;
	std::vector<long>	diff;
	std::copy(_vec.begin(), _vec.end(), std::back_inserter(tmp));
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), std::back_inserter(diff));
	return *std::min_element(++diff.begin(), diff.end());
}

long	Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw (SpanCalculationException());
	std::vector<long>	tmp;
	std::copy(_vec.begin(), _vec.end(), std::back_inserter(tmp));
	std::sort(tmp.begin(), tmp.end());
	return (long)*std::max_element(tmp.begin(), tmp.end())
		- (long)*std::min_element(tmp.begin(), tmp.end());
}

int	Span::get_size() const
{
	return _vec.size();
}

const char	*Span::MaxCapacityException::what() const throw()
{
	return "Operation would exceed max capacity, can't add more numbers";
}

const char	*Span::SpanCalculationException::what() const throw()
{
	return "Can't calculate span. At least 2 numbers are needed.";
}
