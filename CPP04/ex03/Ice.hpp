/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 09:32:51 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/19 10:02:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string	_type;
	public:
		Ice();
		Ice(const Ice &copy);
		~Ice();
		Ice		&operator=(const Ice &copy);
		Ice		*clone() const;
		void	use(ICharacter &target);
};

#endif