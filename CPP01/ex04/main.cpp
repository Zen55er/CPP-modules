/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:24:41 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/03 10:54:35 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int ac, char **av)
{	
	if (ac != 4)
	{
		std::cout << "Usage: ./replace path_to_file string_to_replace replacement_string";
		return (1);
	}
	return (replace(av[1], av[2], av[3]));
}

/* int	main(void)
{
	replace("test_simple", "abc", "def");
	replace("test_multiple", "123", "789");
	replace("test_no_match", "123", "456");
	replace("test_empty", "123", "456");
	replace("test_null", "123", "456");
	return (0);
} */