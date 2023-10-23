/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:12:55 by gacorrei          #+#    #+#             */
/*   Updated: 2023/10/23 14:07:43 by gacorrei         ###   ########.fr       */
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

PmergeMe::PmergeMe()
	: _odd(false), _elements(0), _start_time(0), _v_time(0), _l_time(0) {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	_odd = copy._odd;
	_elements = copy._elements;
	_v_time = copy._v_time;
	_l_time = copy._l_time;
	return *this;
}

void	PmergeMe::sorter(char **input)
{
	try
	{
		input_validation(input);
		v_processor(input);
		l_processor(input);
		final_print();
	}
	catch(const std::runtime_error &error)
	{
		std::cerr << error.what() << std::endl;
	}
}

void	PmergeMe::v_processor(char **input)
{
	std::clock_t		end_sim;
	std::pair<int, int>	temp;
	V_PAIR				pairs;
	int					max;
	int					min;

	_start_time = std::clock();
	for (int i = 0; input[i]; i++)
	{
		if (i % 2)
		{
			max = std::max(atoi(input[i - 1]), atoi(input[i]));
			min = std::min(atoi(input[i - 1]), atoi(input[i]));
			temp = std::make_pair(min, max);
			pairs.push_back(temp);
		}
		if (!input[i + 1] && _odd)
			temp = std::make_pair(atoi(input[i]), atoi(input[i]));
	}
	pairs = v_sort_pairs(pairs);
	if (_odd)
		pairs.push_back(temp);

	std::vector<int>	chain = v_copy_big(pairs);

	v_copy_small(pairs, &chain);
	end_sim = std::clock();
	_v_time = static_cast<double>(end_sim - _v_time) / CLOCKS_PER_SEC * 1000;

	std::vector<int>::iterator begin = chain.begin();
	std::vector<int>::iterator end = chain.end();

	std::cout << "After:\t";
	for (; begin != end; begin++)
		std::cout << *begin << " ";
	std::cout << std::endl;
	// v_check_sorted(chain);
}

void	PmergeMe::l_processor(char **input)
{
	std::clock_t		end_sim;
	std::pair<int, int> temp;
	L_PAIR				pairs;
	int					max;
	int					min;

	_start_time = std::clock();
	for (int i = 0; input[i]; i++)
	{
		if (i % 2)
		{
			max = std::max(atoi(input[i - 1]), atoi(input[i]));
			min = std::min(atoi(input[i - 1]), atoi(input[i]));
			temp = std::make_pair(min, max);
			pairs.push_back(temp);
		}
		if (!input[i + 1] && _odd)
			temp = std::make_pair(atoi(input[i]), atoi(input[i]));
	}
	pairs = l_sort_pairs(pairs);
	if (_odd)
		pairs.push_back(temp);

	std::list<int>	chain = l_copy_big(pairs);

	l_copy_small(pairs, &chain);
	end_sim = std::clock();
	_l_time = static_cast<double>(end_sim - _l_time) / CLOCKS_PER_SEC * 1000;

	/* std::list<int>::iterator begin = chain.begin();
	std::list<int>::iterator end = chain.end();

	std::cout << "Sorted with list: ";
	for (; begin != end; begin++)
		std::cout << *begin << " ";
	std::cout << std::endl; */
	// l_check_sorted(chain);
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
			|| test <= 0 || test > std::numeric_limits<int>::max())
			throw(std::runtime_error("Error: use ONLY positive ints"));
	}
	if (i % 2)
		_odd = true;
	_elements = i;
	std::cout << "Before:\t";
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
	V_PAIR	r_half(pairs.begin() + size, pairs.end());

	l_half = v_sort_pairs(l_half);
	r_half = v_sort_pairs(r_half);

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
	std::copy(it, pairs.end(), std::back_inserter(r_half));

	l_half = l_sort_pairs(l_half);
	r_half = l_sort_pairs(r_half);

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

void	PmergeMe::v_copy_small(V_PAIR pairs, std::vector<int> *chain)
{
	V_IT	begin = pairs.begin() + 1;
	V_IT	end = pairs.end() - 1;
	V_IT	section_end;
	bool	check = false;

	for (int i = 0; begin <= end; i++)
	{
		section_end = jacob_diff[i] <= std::distance(begin, end) ?
			begin + jacob_diff[i] : end;
		if (section_end == end)
			check = true;
		while (section_end >= begin)
		{
			chain->insert(std::lower_bound(chain->begin(), chain->end(),
				section_end->first), section_end->first);
			section_end--;
		}
		if (check)
			break;
	}
}

void	PmergeMe::l_copy_small(L_PAIR pairs, std::list<int> *chain)
{
	L_IT	begin = pairs.begin();
	L_IT	end = pairs.end();

	std::advance(begin, 1);
	std::advance(end, -1);

	L_IT	section_end;
	bool	check = false;

	for (int i = 0; begin != end; i++)
	{
		if (jacob_diff[i] <= std::distance(begin, end))
		{
			section_end = begin;
			std::advance(section_end, jacob_diff[i]);
		}
		else
		{
			section_end = end;
			check = true;
		}
		while (section_end != begin)
		{
			chain->insert(std::lower_bound(chain->begin(), chain->end(),
				section_end->first), section_end->first);
			section_end--;
			if (section_end == begin)
				chain->insert(std::lower_bound(chain->begin(), chain->end(),
					section_end->first), section_end->first);
		}
		if (check)
			break;
	}
}

void	PmergeMe::v_check_sorted(std::vector<int> final)
{
	std::vector<int>::iterator	begin = ++final.begin();
	std::vector<int>::iterator	end = final.end();

	for (; begin != end; begin++)
	{
		if (*begin < *(begin - 1))
		{
			std::cout << "NOT SORTED\n";
			return;
		}
	}
	std::cout << "SORTED\n";
}

void	PmergeMe::l_check_sorted(std::list<int> final)
{
	std::list<int>::iterator	begin = final.begin();
	std::list<int>::iterator	end = final.end();
	std::list<int>::iterator	temp;

	std::advance(begin, 1);
	while (begin != end)
	{
		temp = begin;
		std::advance(temp, -1);
		if (*begin < *temp)
		{
			std::cout << "NOT SORTED\n";
			return;
		}
		std::advance(begin, 1);
	}
	std::cout << "SORTED\n";
}

void	PmergeMe::final_print()
{
	std::cout << "Time to process a range of " << _elements
		<< " elements with std::vector : " << _v_time << " ms\n";
	std::cout << "Time to process a range of " << _elements
		<< " elements with std::list : " << _l_time << " ms\n";
}
