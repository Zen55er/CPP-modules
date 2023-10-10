/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:57:20 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:30 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void	tester(T container)
{
	container.push_back(1);
	container.push_back(2);
	container.push_back(3);
	container.push_back(4);
	container.push_back(5);
	typename T::iterator	it = container.begin();
	for (; it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	easyfind(container, 6);
	easyfind(container, 3);
}

int	main(void)
{
		std::cout << "TESTING WITH VECTOR\n";
		std::vector<int>	vec;
		tester(vec);
		std::cout << "TESTING WITH DEQUE\n";
		std::deque<int>	deq;
		tester(deq);
		std::cout << "TESTING WITH LIST\n";
		std::list<int>	lst;
		tester(lst);
	return 0;
}
