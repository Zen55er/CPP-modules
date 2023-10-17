/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/16 14:14:40 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>

#define V_IT std::vector<std::pair<int,int> >::iterator
#define L_IT std::list<std::pair<int,int> >::iterator

class PmergeMe
{
	private:
		std::vector<std::pair<int,int> >	_vec;
		std::list<std::pair<int,int> >		_lst;
		std::vector<int>					_v_largest;
		std::list<int>						_l_largest;
		bool								_odd;
		static int64_t						jacob_diff[];
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &copy);
		int			input_validation(char **input);
		void		sorter(char **input);
		void		v_processor(char **input);
		void		l_processor(char **input);
		void		v_sort_pairs();
		void		l_sort_pairs();
		void		v_prep_largest(V_IT begin);
		void		l_prep_largest(L_IT begin);
};
