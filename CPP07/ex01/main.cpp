/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:35:45 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/06 12:56:46 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int	len = 5;

	std::cout << "TESTING WITH INT ARRAY\n";
	int	arr1[] = {1, 2, 3, 4, 5};

	::iter(arr1, len, func<int>);

	std::cout << "\nTESTING WITH CHAR ARRAY\n";
	char	arr2[] = {'a', 'b', 'c', 'd', 'e'};

	::iter(arr2, len, func<char>);
	
	std::cout << "\nTESTING WITH STRING ARRAY\n";
	std::string	arr3[] = {"ALPHA", "BETA", "EPSILON", "GAMMA", "KAPPA"};

	::iter(arr3, len, func<std::string>);

	std::cout << "\nTESTING WITH FLOAT ARRAY\n";
	float	arr4[] = {1.0, 2.1, 3.2, 4.3, 5.4};

	::iter(arr4, len, func2<float>);
	return 0;
}
