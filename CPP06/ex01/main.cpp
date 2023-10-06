/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:48:25 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/06 09:00:53 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	a;
	Data	b;
	Data	c;
	Data	d;
	Data	e;

	a.text = "Oh, ";
	a.val = 1;
	b.text = "sugar ";
	b.val = 2;
	c.text = "honey ";
	c.val = 3;
	d.text = "ice ";
	d.val = 4;
	e.text = "tea.";
	e.val = 5;

	std::cout << a.text << b.text << c.text << d.text << e.text << std::endl;
	std::cout << a.val << b.val << c.val << d.val << e.val << std::endl;

	uintptr_t	aa;
	uintptr_t	bb;
	uintptr_t	cc;
	uintptr_t	dd;
	uintptr_t	ee;

	aa = Serializer::serialize(&a);
	bb = Serializer::serialize(&b);
	cc = Serializer::serialize(&c);
	dd = Serializer::serialize(&d);
	ee = Serializer::serialize(&e);

	Data	*a2;
	Data	*b2;
	Data	*c2;
	Data	*d2;
	Data	*e2;

	a2 = Serializer::deserialize(aa);
	b2 = Serializer::deserialize(bb);
	c2 = Serializer::deserialize(cc);
	d2 = Serializer::deserialize(dd);
	e2 = Serializer::deserialize(ee);

	std::cout << a2->text << b2->text << c2->text << d2->text << e2->text << std::endl;
	std::cout << a2->val << b2->val << c2->val << d2->val << e2->val << std::endl;
}
