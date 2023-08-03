/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:17:09 by gacorrei          #+#    #+#             */
/*   Updated: 2023/08/03 10:51:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	replace(std::string filename, std::string str1, std::string str2)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;
	std::size_t		pos;
	std::size_t		len;

	infile.open(filename.c_str(), std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "Failed to open infile: " << filename << std::endl;
		return (1);
	}
	outfile.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
	{
		std::cout << "Failed to open outfile from infile: " << filename << std::endl;
		return (1);
	}
	len = str1.length();
	while (getline(infile, line))
	{
		pos = line.find(str1, 0);
		while (pos != std::string::npos)
		{
			line.erase(pos, len);
			line.insert(pos, str2);
			pos = line.find(str1, 0);
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}