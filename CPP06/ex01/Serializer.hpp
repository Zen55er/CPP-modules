/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:17:57 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/05 16:19:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer() {}

Serializer(const Serializer &copy)
{
	void(copy);
}

~Serializer() {}

Serializer &operator=(const Serializer &copy)
{
	void(copy);
	return *this;
}

uintptr_t	serialize(Data* ptr)
{
	
}

Data	*deserialize(uintptr_t raw)
{

}
