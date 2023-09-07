/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:49:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/07 14:59:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	magnate;

	std::cout << magnate;
	magnate.upgrade();
	std::cout << magnate;
	magnate.upgrade();
	std::cout << magnate;
	magnate.downgrade();
	std::cout << magnate;
	magnate.setGrade(1);
	std::cout << magnate;
	magnate.downgrade();
	std::cout << magnate;
	return (0);
}
