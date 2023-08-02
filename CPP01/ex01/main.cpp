/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:24:13 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/02 10:42:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		n;

	n = 10;
	horde = zombieHorde(n, "Feral Ghoul");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
}
