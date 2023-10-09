/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:44:02 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/09 14:22:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

typedef struct Data
{
	std::string	text;
	int			val;
} Data;

int	main(void)
{
	try
	{
		std::cout << "TESTING WITH EMPTY INT ARRAY\n";
		Array<int> arr0;

		std::cout << "arr0, pos 0 is: " << arr0[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\nTESTING WITH INT ARRAY\n";
		Array<int> arr1(10);

		for (unsigned int i = 0; i < arr1.size(); i++)
			arr1[i] = i;
		std::cout << "arr1 size is: " << arr1.size() << std::endl;
		for (unsigned int i = 0; i < arr1.size(); i++)
			std::cout << "arr1 pos " << i << " is: " << arr1[i] << std::endl;

		std::cout << "\nTESTING WITH CHAR ARRAY\n";
		Array<char>	arr2(5);

		for (unsigned int i = 0; i < arr2.size(); i++)
			arr2[i] = i + 97;
		std::cout << "arr2 size is: " << arr2.size() << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << "arr2 pos " << i << " is: " << arr2[i] << std::endl;

		std::cout << "\nTESTING WITH STRING ARRAY\n";
		Array<std::string>	arr3(5);

		arr3[0] = "ALPHA";
		arr3[1] = "BETA";
		arr3[2] = "EPSILON";
		arr3[3] = "GAMMA";
		arr3[4] = "KAPPA";
		std::cout << "arr3 size is: " << arr3.size() << std::endl;
		for (unsigned int i = 0; i < arr3.size(); i++)
			std::cout << "arr3 pos " << i << " is: " << arr3[i] << std::endl;

		std::cout << "\nTESTING WITH FLOAT ARRAY\n";
		Array<float>	arr4(6);

		for (unsigned int i = 0; i < arr4.size(); i++)
			arr4[i] = (float)i + ((float)i * 0.5);
		std::cout << "arr4 size is: " << arr4.size() << std::endl;
		for (unsigned int i = 0; i < arr4.size(); i++)
			std::cout << "arr4 pos " << i << " is: " << arr4[i] << std::endl;

		std::cout << "\nTESTING DEEP COPY\n";
		Array<float>	arr5;

		arr5 = arr4;
		for (unsigned int i = 0; i < arr5.size(); i++)
			arr5[i] = (float)i + ((float)i * 2.5 + 1.0);
		std::cout << "arr5 size is: " << arr5.size() << std::endl;
		for (unsigned int i = 0; i < arr5.size(); i++)
			std::cout << "arr5 pos " << i << " is: " << arr5[i] << std::endl;
		std::cout << std::endl;
		for (unsigned int i = 0; i < arr4.size(); i++)
			std::cout << "arr4 pos " << i << " is: " << arr4[i] << std::endl;
		
		std::cout << "\nTESTING WITH DATA ARRAY\n";
		Array<Data>	arr6(3);

		arr6[0].text = "ABC";
		arr6[0].val = 123;
		arr6[1].text = "DEF";
		arr6[1].val = 465;
		arr6[2].text = "GHI";
		arr6[2].val = 789;
		std::cout << "arr6 size is: " << arr6.size() << std::endl;
		for (unsigned int i = 0; i < arr6.size(); i++)
		{
			std::cout << "arr6 pos " << i << " text is: " << arr6[i].text << std::endl;
			std::cout << "arr6 pos " << i << " val is: " << arr6[i].val << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
