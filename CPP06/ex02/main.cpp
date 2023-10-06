/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:11:41 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/06 10:54:24 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int	random;

	random = 1 + (rand() % 3);
	switch (random)
	{
		case 1:
			std::cout << "Created a pointer of type A\n";
			return new A();
		case 2:
			std::cout << "Created a pointer of type B\n";
			return new B();
		case 3:
			std::cout << "Created a pointer of type C\n";
			return new C();
		default:
			std::cout << "Failed to create a pointer\n";
			return NULL;
	}
}

void	identify(Base *p)
{
	A	*test_a = dynamic_cast<A*>(p);
	B	*test_b = dynamic_cast<B*>(p);
	C	*test_c = dynamic_cast<C*>(p);

	if (test_a)
		std::cout << "Pointer p is of type A\n";
	else if (test_b)
		std::cout << "Pointer p is of type B\n";
	else if (test_c)
		std::cout << "Pointer p is of type C\n";
	else
		std::cout << "Pointer p is not of type A, B or C\n";
}

void	identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "Reference p is of type A\n";
	}
	catch(const std::exception &error)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			std::cout << "Reference p is of type B\n";
		}
		catch(const std::exception &error)
		{
			try
			{
				(void) dynamic_cast<C&>(p);
				std::cout << "Reference p is of type C\n";
			}
			catch(const std::exception &error)
			{
				std::cout << "Reference p is not of type A, B or C\n";
			}
		}
	}
}

int	main(void)
{
	Base	*ptr;

	for (int i = 0; i < 10; i++)
	{
		ptr = generate();

		identify(ptr);
		identify(*ptr);
		if (ptr)
			delete ptr;
		std::cout << std::endl;
	}
}
