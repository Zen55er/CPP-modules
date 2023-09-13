/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:53:13 by gacorrei          #+#    #+#             */
/*   Updated: 2023/09/13 12:13:23 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Main street") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm("ShrubberyCreationForm", 145, 137), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->_target = copy._target;
	this->setSigned(this->isSigned());
	return (*this);
}

void	ShrubberyCreationForm::executor() const
{
	std::ofstream	out;
	static int		choice;

	out.open((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::app);
	if (!out.is_open())
	{
		std::cout << "Failed to open outfile" << std::endl;
		return ;
	}
	if (choice % 2)
		out << ShrubberyCreationForm::_tree1;
	else
		out << ShrubberyCreationForm::_tree2;
	choice++;
	out.close();
	return ;
}

const std::string	ShrubberyCreationForm::_tree1 =
"	 oxoxoo    ooxoo\n"
"  ooxoxo oo  oxoxooo\n"
" oooo xxoxoo ooo ooox\n"
" oxo o oxoxo  xoxxoxo\n"
"  oxo xooxoooo o ooo\n"
"    ooo\\oo\\  /o/o\n"
"        \\  \\/ /\n"
"         |   /\n"
"         |  |\n"
"         | D|\n"
"         |  |\n"
"         |  |\n"
"  ______/____\\____\n";

const std::string	ShrubberyCreationForm::_tree2 =
"              _{\\ _{\\{\\/}/}/}__\n"
"             {/{/\\}{/{/\\}(\\}{/\\} _\n"
"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
"             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
"              {){/ {\\/}{\\/} \\}\\}\n"
"              (_)  \\.-'.-/\n"
"          __...--- |'-.-'| --...__\n"
"   _...--    .-'   |'-.-'|  ' -.    --..__\n"
" -     ' .  . '    |.'-._| '  . .  '      \n"
" .  '-  '    .--'  | '-.'|    .  '  . '\n"
"          ' ..     |'-_.-|\n"
"  .  '  .       _.-|-._ -|-._  .  '  .\n"
"              .'   |'- .-|   '.\n"
"  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
"   .-' '        '-._______.-'     '  .\n"
"        .      ~,\n"
"    .       .   |\\   .    ' '-.\n";
