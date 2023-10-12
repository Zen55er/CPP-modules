/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:17:25 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/12 09:09:22 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "SUBJECT MAIN\n";
		MutantStack<int> m_stack;
		m_stack.push(5);
		m_stack.push(17);
		std::cout << m_stack.top() << std::endl;
		m_stack.pop();
		std::cout << m_stack.size() << std::endl;
		m_stack.push(3);
		m_stack.push(5);
		m_stack.push(737);
		m_stack.push(0);
		MutantStack<int>::iterator it = m_stack.begin();
		MutantStack<int>::iterator ite = m_stack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(m_stack);
	}
	{
		std::cout << "SUBJECT MAIN WITH LIST\n";
		std::list<int> m_stack;
		m_stack.push_back(5);
		m_stack.push_back(17);
		std::cout << m_stack.back() << std::endl;
		m_stack.pop_back();
		std::cout << m_stack.size() << std::endl;
		m_stack.push_back(3);
		m_stack.push_back(5);
		m_stack.push_back(737);
		m_stack.push_back(0);
		std::list<int>::iterator it = m_stack.begin();
		std::list<int>::iterator ite = m_stack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "PROOF THAT ITERATORS WORK\n";
		MutantStack<int> m_stack;

		m_stack.push(1);
		m_stack.push(2);
		m_stack.push(3);
		m_stack.push(4);
		m_stack.push(5);
		MutantStack<int>::iterator begin = m_stack.begin();
		MutantStack<int>::iterator end = m_stack.end();
		int	size = m_stack.size();
		std::cout << "Size: " << size << std::endl;
		for (; begin != end; begin++)
			std::cout << "Value: " << *begin << std::endl;
	}
	return 0;
}
