/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:29:38 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/03 17:25:34 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
AForm("default name", 25, 5),
_target("PresidentialPardonForm")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm", 25, 5),
_target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
AForm(src),
_target(src._target)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	checkExecuteRequirement(executor);
	std::cout << CYAN << this->_target <<  " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
