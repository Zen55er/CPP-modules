/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:08:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/11 15:08:39 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class RPN
{
	private:
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN &operator=(const RPN &copy);
};
