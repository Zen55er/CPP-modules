/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:09:22 by gacorrei          #+#    #+#             */
/*   Updated: 2024/01/13 11:04:45 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "DEBUG" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "INFO" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "ERROR" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

// If you are having trouble understanding the code, read this:
// https://isocpp.org/wiki/faq/pointers-to-members

// If you get a compiler warning about "may be used uninitialized",
// AND you are sure that the iterator cannot go beyond the array,
// you can ignore it. It's a false positive (use -Wno-maybe-uninitialized in Makefile)

typedef void (Harl::*choice)(void);
#define CALL_CHOICE_FN(object, ptrToMember)  ((object).*(ptrToMember))

void Harl::complain(std::string level)
{
	choice		choices[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			CALL_CHOICE_FN(*this, choices[i])();
			break ;
		}
	}
}
