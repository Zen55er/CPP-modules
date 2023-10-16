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

class PmergeMe
{
	private:
		std::vector<std::pair<int,int> > _vec;
		std::list<std::pair<int,int> > _lst;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe	&operator=(const PmergeMe &copy);
		void		sorter(char **input);
		void		processor(char **input, bool type);
		int			input_validation(std::string input);
};
