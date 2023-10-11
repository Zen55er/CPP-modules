/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:55:58 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/11 10:57:10 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		std::cout << "TESTING SUBJECT MAIN\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\nTESTING EXCEPTIONS\n";
		Span				s0;
		Span				s1(5);
		std::vector<int>	v0;

		v0.push_back(1);
		v0.push_back(2);
		try
		{
			s0.addNumber(1);
		}
		catch(Span::MaxCapacityException &error)
		{
			std::cerr << error.what() << '\n';
		}
		try
		{
			s0.addRange(v0.begin(), v0.end());
		}
		catch(Span::MaxCapacityException &error)
		{
			std::cerr << error.what() << '\n';
		}
		try
		{
			s1.addNumber(1);
			s1.shortestSpan();
		}
		catch(Span::SpanCalculationException &error)
		{
			std::cerr << error.what() << '\n';
		}
	}
	{
		std::cout << "\nTESTING 10000 NUMBERS\n";
		unsigned int		max = 10000;
		Span				s2(max);
		std::vector<int>	v1(max);

		srand(time(NULL));
		std::generate(v1.begin(), v1.end(), std::rand);
		s2.addRange(v1.begin(), v1.end());
		std::cout << "s2 size is: " << s2.get_size() << std::endl;
		std::cout << "Shortest span is: " << s2.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << s2.longestSpan() << std::endl;
	}
	{
		std::cout << "\nTESTING 100000 NUMBERS\n";
		unsigned int		max = 100000;
		Span				s3(max);
		std::vector<int>	v1(max);

		srand(time(NULL));
		std::generate(v1.begin(), v1.end(), std::rand);
		s3.addRange(v1.begin(), v1.end());
		std::cout << "s3 size is: " << s3.get_size() << std::endl;
		std::cout << "Shortest span is: " << s3.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << s3.longestSpan() << std::endl;
	}
	{
		std::cout << "\nTESTING MAX SPAN\n";
		unsigned int		max = 2;
		Span				s4(max);

		s4.addNumber(std::numeric_limits<int>::max());
		s4.addNumber(std::numeric_limits<int>::min());
		std::cout << "s4 size is: " << s4.get_size() << std::endl;
		std::cout << "Shortest span is: " << s4.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << s4.longestSpan() << std::endl;
	}
	{
		std::cout << "\nTEST PLAYGROUND\n";
		unsigned int		max = 5;
		Span				s5(max);

		s5.addNumber(0);
		s5.addNumber(2);
		s5.addNumber(3);
		s5.addNumber(5);
		s5.addNumber(7);
		std::cout << "s5 size is: " << s5.get_size() << std::endl;
		std::cout << "Shortest span is: " << s5.shortestSpan() << std::endl;
		std::cout << "Longest span is: " << s5.longestSpan() << std::endl;
	}
	return 0;
}
