/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:08:57 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/24 13:27:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Error: provide ints to sort\n";
		return 0;
	}

	PmergeMe	fj_mi;

	fj_mi.sorter(++av);
	return 0;
}
