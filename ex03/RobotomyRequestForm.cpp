/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:29:38 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/02 17:53:32 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
AForm("default name", 72, 45),
_target("RobotomyRequestForm")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
AForm(src),
_target(src._target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	checkExecuteRequirement(executor);

	static bool	flag = false;

	if (!flag)
	{
		std::srand(std::time(0));
		flag = true;
	}
	std::cout << "* Zzzzz zzzz  DRILLING NOISES... *" << std::endl;
	if (std::rand() % 2)
	{
		std::cout << GREEN << this->_target << " has been robotomized successfully!" << RESET << std::endl;
	}
	else
		std::cout << RED << "The robotomy on "  << this->_target << " failed."  << RESET << std::endl;
}
