/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:32:55 by gacorrei          #+#    #+#             */
/*   Updated: 2023/07/28 12:06:24 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

#define TIMESTAMP 18

Account( int initial_deposit )
{
	
}

Account( void )
{
	
}

~Account( void )
{
	
}

static int	getNbAccounts( void )
{
	
}

static int	getTotalAmount( void )
{
	
}

static int	getNbDeposits( void )
{
	
}

static int	getNbWithdrawals( void )
{
	
}

static void	displayAccountsInfos( void )
{
	
}

void	makeDeposit( int deposit )
{
	
}

bool	makeWithdrawal( int withdrawal )
{
	
}

int		checkAmount( void ) const
{
	
}

void	displayStatus( void ) const
{
	
}

static void	_displayTimestamp( void )
{
	std::time_t	base_time;
	std::tm		*time;
	char		timestamp[TIMESTAMP];

	//Sets current time
	std::time(&base_time);
	//Passes current time to tm struct format (as local time)
	time = std::localtime(&base_time);
	//Formats output using tm struct fields
	strftime(timestamp, TIMESTAMP, "[%Y%m%d_%H%M%S]", time);
	std::cout << timestamp << std::endl;
	return (0);
}
