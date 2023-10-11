/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/11 13:19:24 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &copy);
		~MutantStack();
		MutantStack<T>	&operator=(const MutantStack<T> &copy);
		typedef typename std::deque<T>::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"
