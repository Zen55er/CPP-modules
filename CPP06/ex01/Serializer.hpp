/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:07:16 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/06 09:01:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
	public:
		~Serializer();
		Serializer &operator=(const Serializer &copy);
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};
