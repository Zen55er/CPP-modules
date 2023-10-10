/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:21:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/10 10:33:08 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

template <typename T>
bool	easyfind(T haystack,  int needle)
{
	typename T::const_iterator	it;
	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end())
	{
		std::cout << "Could not find " << needle << std::endl;
		return false;
	}
	std::cout << "Found " << needle << std::endl;
	return true;
}
