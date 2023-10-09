/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:21:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/09 16:43:16 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
T	easyfind(T haystack,  int needle)
{
	typename T::const_iterator	it = std::find(haystack.begin(), haystack.end(), needle);
	if (i != haystack.end())
		return 0;
	return 1;
}
