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

#define V_PAIR std::vector<std::pair<int,int> >
#define L_PAIR std::list<std::pair<int,int> >
#define V_IT std::vector<std::pair<int,int> >::iterator
#define L_IT std::list<std::pair<int,int> >::iterator
#define I_PAIR	std::pair<int,int>

class PmergeMe
{
	private:
		bool				_odd;
		static int64_t		jacob_diff[];
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe			&operator=(const PmergeMe &copy);
		int					input_validation(char **input);
		void				sorter(char **input);
		void				v_processor(char **input);
		void				l_processor(char **input);
		V_PAIR				v_sort_pairs(V_PAIR pairs);
		L_PAIR				l_sort_pairs(L_PAIR pairs);
		std::vector<int>	v_copy_big(V_PAIR pairs);
		std::list<int>		l_copy_big(L_PAIR pairs);
		void				v_copy_small(V_PAIR pairs, std::vector<int> chain);
		void				l_copy_small(L_PAIR pairs, std::list<int> chain);
		void				v_insert(std::vector<int> chain, int val, int n);
		void				l_insert(std::list<int> chain, int val, int n);
		static bool			cmp_pairs(const I_PAIR &a, const I_PAIR &b);
};
