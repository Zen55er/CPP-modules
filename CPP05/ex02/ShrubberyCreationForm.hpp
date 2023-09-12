/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:52:06 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/12 14:20:28 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
		void					execute(Bureaucrat const &executor) const;

		const std::string		tree1 =
		"	 oxoxoo    ooxoo\n"
		"  ooxoxo oo  oxoxooo\n"
		" oooo xxoxoo ooo ooox\n"
		" oxo o oxoxo  xoxxoxo\n"
		"  oxo xooxoooo o ooo\n"
		"    ooo\oo\  /o/o\n"
		"        \  \/ /\n"
		"         |   /\n"
		"         |  |\n"
		"         | D|\n"
		"         |  |\n"
		"         |  |\n"
		"  ______/____\____\n";

		const std::string		tree2 =
		"              _{\ _{\{\/}/}/}__\n"
		"             {/{/\}{/{/\}(\}{/\} _\n"
		"            {/{/\}{/{/\}(_)\}{/{/\}  _\n"
		"         {\{/(\}\}{/{/\}\}{/){/\}\} /\}\n"
		"        {/{/(_)/}{\{/)\}{\(_){/}/}/}/}\n"
		"       _{\{/{/{\{/{/(_)/}/}/}{\(/}/}/}\n"
		"      {/{/{\{\{\(/}{\{\/}/}{\}(_){\/}\}\n"
		"      _{\{/{\{/(_)\}/}{/{/{/\}\})\}{/\}\n"
		"     {/{/{\{\(/}{/{\{\{\/})/}{\(_)/}/}\}\n"
		"      {\{\/}(_){\{\{\/}/}(_){\/}{\/}/})/}\n"
		"       {/{\{\/}{/{\{\{\/}/}{\{\/}/}\}(_)\n"
		"      {/{\{\/}{/){\{\{\/}/}{\{\(/}/}\}/}\n"
		"       {/{\{\/}(_){\{\{\(/}/}{\(_)/}/}\}\n"
		"         {/({/{\{/{\{\/}(_){\/}/}\}/}(\}\n"
		"          (_){/{\/}{\{\/}/}{\{\)/}/}(_)\n"
		"            {/{/{\{\/}{/{\{\{\(_)/}\n"
		"             {/{\{\{\/}/}{\{\\}/}\n"
		"              {){/ {\/}{\/} \}\}\n"
		"              (_)  \.-'.-/\n"
		"          __...--- |'-.-'| --...__\n"
		"   _...--"   .-'   |'-.-'|  ' -.  ""--..__\n"
		" -"    ' .  . '    |.'-._| '  . .  '      \n"
		" .  '-  '    .--'  | '-.'|    .  '  . '\n"
		"          ' ..     |'-_.-|\n"
		"  .  '  .       _.-|-._ -|-._  .  '  .\n"
		"              .'   |'- .-|   '.\n"
		"  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
		"   .-' '        '-._______.-'     '  .\n"
		"        .      ~,\n"
		"    .       .   |\   .    ' '-.\n";
};
