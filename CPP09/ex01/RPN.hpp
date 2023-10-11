/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:08:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/11 15:42:49 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
	private:
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN &operator=(const RPN &copy);
};
