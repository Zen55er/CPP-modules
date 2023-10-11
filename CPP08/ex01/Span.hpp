/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:06:13 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/11 10:53:23 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <vector>
#include <iterator>
#include <algorithm>

#define VEC_INT std::vector<int>

class Span
{
	private:
		size_t	_max_size;
		VEC_INT	_vec;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();
		Span 	&operator=(const Span &copy);
		void	addNumber(int num);
		void	addRange(VEC_INT::iterator begin, VEC_INT::iterator end);
		long	shortestSpan() const;
		long	longestSpan() const;
		int		get_size() const;

		class	MaxCapacityException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class	SpanCalculationException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};
