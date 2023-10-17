/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:55 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/16 14:32:11 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int64_t	PmergeMe::jacob_diff[] =
{
	2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
    2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
    1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
    178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
    11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
    366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
    11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
    375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
    6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
    96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
    1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};

PmergeMe::PmergeMe(): _odd(false) {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	_vec = copy._vec;
	_lst = copy._lst;
	_odd = copy._odd;
	return *this;
}

void	PmergeMe::sorter(char **input)
{
	try
	{
		input_validation(input);
		v_processor(input);
		l_processor(input);
	}
	catch(const std::runtime_error &error)
	{
		std::cerr << error.what() << std::endl;
	}
}

void	PmergeMe::v_processor(char **input)
{
	std::pair<int, int> temp;

	for (int i = 0; input[i]; i++)
	{
		if (i % 2)
		{
			temp = std::make_pair(atoi(input[i - 1]), atoi(input[i]));
			_vec.push_back(temp);
		}
		if (!input[i + 1] && _odd)
		{
			temp = std::make_pair(atoi(input[i]), atoi(input[i]));
			_vec.push_back(temp);
		}
	}
	v_sort_pairs();
}

void	PmergeMe::l_processor(char **input)
{
	std::pair<int, int> temp;

	for (int i = 0; input[i]; i++)
	{
		if (i % 2)
		{
			temp = std::make_pair(atoi(input[i - 1]), atoi(input[i]));
			_lst.push_back(temp);
		}
		if (!input[i + 1] && _odd)
		{
			temp = std::make_pair(atoi(input[i]), atoi(input[i]));
			_lst.push_back(temp);
		}
	}
	l_sort_pairs();
}

int		PmergeMe::input_validation(char **input)
{
	long				test;
	std::stringstream	st;
	char				c;
	int					i = 0;

	for (; input[i]; i++)
	{
		st.clear();
		st << input[i];
		while (st >> c)
			if (!isdigit(c))
				throw(std::runtime_error("Error: use ONLY positive ints"));
		test = strtoul(input[i], NULL, 0);
		if ((!test && static_cast<std::string>(input[i]).compare("0"))
			|| test < 0 || test > std::numeric_limits<int>::max())
			throw(std::runtime_error("Error: use ONLY positive ints"));
	}
	if (!(i % 2))
		_odd = true;
	std::cout << "Before: ";
	for (i = 0; input[i]; i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;
	return 0;
}

void	PmergeMe::v_sort_pairs()
{
	V_IT	v_begin = _vec.begin();
	V_IT	v_end = _vec.end();

	for (; v_begin != v_end; v_begin++)
		if (v_begin->first > v_begin->second)
			std::swap(v_begin->first, v_begin->second);
	v_prep_largest(_vec.begin());
}

void	PmergeMe::l_sort_pairs()
{
	L_IT	l_begin = _lst.begin();
	L_IT	l_end = _lst.end();

	for (; l_begin != l_end; l_begin++)
		if (l_begin->first > l_begin->second)
			std::swap(l_begin->first, l_begin->second);
	l_prep_largest(_lst.begin());
}

void	PmergeMe::v_prep_largest(V_IT begin)
{

}

void	PmergeMe::l_prep_largest(L_IT begin)
{

}
