/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:07:16 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/05 16:17:49 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
	public:
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer &operator=(const Serializer &copy);
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
}
