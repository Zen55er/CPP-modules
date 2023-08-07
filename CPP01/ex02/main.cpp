/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:46:18 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/07 09:19:17 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string is: " << &string << std::endl;
	std::cout << "Address of stringPTR is: " << stringPTR << std::endl;
	std::cout << "Address of stringREF is: " << &stringREF << std::endl;
	std::cout << "string is: " << string << std::endl;
	std::cout << "stringPTR is: " << *stringPTR << std::endl;
	std::cout << "stringREF is: " << stringREF << std::endl;
}
