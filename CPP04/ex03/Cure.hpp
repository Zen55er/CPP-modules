/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:01:06 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/19 10:02:38 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string	_type;
	public:
		Cure();
		Cure(const Cure &copy);
		~Cure();
		Cure	&operator=(const Cure &copy);
		Cure	*clone() const;
		void 	use(ICharacter &target);
};

#endif