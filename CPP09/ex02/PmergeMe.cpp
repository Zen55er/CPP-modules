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
	std::pair<int, int>	temp;
	V_PAIR				pairs;

	for (int i = 0; input[i]; i++)
	{
		if (i % 2)
		{
			temp = std::make_pair(atoi(input[i - 1]), atoi(input[i]));
			pairs.push_back(temp);
		}
		if (!input[i + 1] && _odd)
		{
			temp = std::make_pair(atoi(input[i]), atoi(input[i]));
			pairs.push_back(temp);
		}
	}
	pairs = v_sort_pairs(pairs);

	std::vector<int>	chain = v_copy_big(pairs);

	v_copy_small(pairs, chain);

	std::vector<int>::iterator begin = chain.begin();
	std::vector<int>::iterator end = chain.end();

	std::cout << "Sorted with vector: ";
	for (; begin != end; begin++)
		std::cout << *begin;
	std::cout << std::endl;
}

void	PmergeMe::l_processor(char **input)
{
	std::pair<int, int> temp;
	L_PAIR				pairs;

	for (int i = 0; input[i]; i++)
	{
		if (i % 2)
		{
			temp = std::make_pair(atoi(input[i - 1]), atoi(input[i]));
			pairs.push_back(temp);
		}
		if (!input[i + 1] && _odd)
		{
			temp = std::make_pair(atoi(input[i]), atoi(input[i]));
			pairs.push_back(temp);
		}
	}
	pairs = l_sort_pairs(pairs);

	std::list<int>	chain = l_copy_big(pairs);

	l_copy_small(pairs, chain);

	std::list<int>::iterator begin = chain.begin();
	std::list<int>::iterator end = chain.end();

	std::cout << "Sorted with list: ";
	for (; begin != end; begin++)
		std::cout << *begin;
	std::cout << std::endl;
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

V_PAIR	PmergeMe::v_sort_pairs(V_PAIR pairs)
{
	int	size = pairs.size();

	if (size < 2)
		return pairs;
	size /= 2;

	V_PAIR	l_half(pairs.begin(), pairs.begin() + size);
	V_PAIR	r_half(pairs.begin() + size, _odd ? --pairs.end() : pairs.end());

	v_sort_pairs(l_half);
	v_sort_pairs(r_half);

	V_PAIR	merged;

	std::merge(l_half.begin(), l_half.end(), r_half.begin(), r_half.end(),
		std::back_inserter(merged), cmp_pairs);
	return merged;
}

L_PAIR	PmergeMe::l_sort_pairs(L_PAIR pairs)
{
	int	size = pairs.size();

	if (size < 2)
		return pairs;
	size /= 2;

	L_PAIR	l_half;
	L_PAIR	r_half;
	L_IT	it = pairs.begin();
	std::advance(it, size);
	std::copy(pairs.begin(), it, std::back_inserter(l_half));
	std::copy(it, _odd ? --pairs.end() : pairs.end(),
		std::back_inserter(l_half));

	l_sort_pairs(l_half);
	l_sort_pairs(r_half);

	L_PAIR	merged;

	std::merge(l_half.begin(), l_half.end(), r_half.begin(), r_half.end(),
		std::back_inserter(merged), cmp_pairs);
	return merged;
}

bool	PmergeMe::cmp_pairs(const I_PAIR &a, const I_PAIR &b)
{
	if (a.second < b.second)
		return true;
	return false;
}

std::vector<int>	PmergeMe::v_copy_big(V_PAIR pairs)
{
	V_IT				begin = pairs.begin();
	V_IT				end = _odd ? --pairs.end() : pairs.end();
	std::vector<int>	chain;

	chain.push_back(begin->first);
	for (; begin != end; begin++)
		chain.push_back(begin->second);
	return chain;
}

std::list<int>		PmergeMe::l_copy_big(L_PAIR pairs)
{
	L_IT				begin = pairs.begin();
	L_IT				end = _odd ? --pairs.end() : pairs.end();
	std::list<int>	chain;

	chain.push_back(begin->first);
	for (; begin != end; begin++)
		chain.push_back(begin->second);
	return chain;
}

void	PmergeMe::v_copy_small(V_PAIR pairs, std::vector<int> chain)
{
	V_IT	begin = pairs.begin() + 1;
	V_IT	end = pairs.end();
	V_IT	section_end;
	bool	check = false;

	for (int i = 0; begin != end; i++)
	{
		section_end = jacob_diff[i] <= std::distance(begin, end) ?
			begin + jacob_diff[i] : end;
		if (section_end == end)
			check = true;
		while (section_end != begin)
		{
			v_insert(chain, section_end->first,
				std::distance(pairs.begin(), section_end));
			section_end--;
		}
		if (check)
			break;
	}
}

void	PmergeMe::l_copy_small(L_PAIR pairs, std::list<int> chain)
{
	L_IT	begin = pairs.begin();
	L_IT	end = pairs.end();
	L_IT	section_end;
	bool	check = false;

	std::advance(begin, 1);
	for (int i = 0; begin != end; i++)
	{
		if (jacob_diff[i] <= std::distance(begin, end))
		{
			section_end = begin;
			std::advance(section_end, jacob_diff[i]);
		}
		else
			section_end = end;
		if (section_end == end)
			check = true;
		while (section_end != begin)
		{
			l_insert(chain, section_end->first,
				std::distance(pairs.begin(), section_end));
			section_end--;
		}
		if (check)
			break;
	}
}

void	PmergeMe::v_insert(std::vector<int> chain, int val, int n)
{
	std::vector<int>::iterator	begin = chain.begin();
	std::vector<int>::iterator	max_check = chain.begin() + n;

	chain.insert(std::lower_bound(begin, max_check, val), val);
}

void	PmergeMe::l_insert(std::list<int> chain, int val, int n)
{
	std::list<int>::iterator	begin = chain.begin();
	std::list<int>::iterator	max_check = chain.begin();

	std::advance(max_check, n);
	chain.insert(std::lower_bound(begin, max_check, val), val);
}
