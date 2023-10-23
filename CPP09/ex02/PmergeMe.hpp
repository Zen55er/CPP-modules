/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/23 12:32:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <limits>
#include <ctime>
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
		int					_elements;
		static int64_t		jacob_diff[];
		std::clock_t		_start_time;
		double				_v_time;
		double				_l_time;
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
		void				v_copy_small(V_PAIR pairs, std::vector<int> *chain);
		void				l_copy_small(L_PAIR pairs, std::list<int> *chain);
		static bool			cmp_pairs(const I_PAIR &a, const I_PAIR &b);
		void				v_check_sorted(std::vector<int> final);
		void				l_check_sorted(std::list<int> final);
		void				final_print();
};
