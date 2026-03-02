/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:29:38 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/02 17:09:40 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
AForm("default name", 145, 137),
_target("ShrubberyCreationForm")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm", 145, 137),
_target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):
AForm(src),
_target(src._target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	std::string	filename;
	std::ofstream	ofs;

	checkExecuteRequirement(executor);

	filename = this->_target + "_shrubbery";
	ofs.open(filename.c_str());
	if (!ofs.is_open())
	{
		throw (FileOpenException());
	}
	ofs << "      /\\      " << std::endl;
	ofs << "     /\\*\\     " << std::endl;
	ofs << "    /\\O\\*\\    " << std::endl;
	ofs << "   /*/\\/\\/\\   " << std::endl;
	ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
	ofs << "      ||      " << std::endl;
	ofs.close();
	std::cout << YELLOW << "Shrubbery was created at " << filename << RESET << std::endl;
}
