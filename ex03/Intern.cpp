/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:21:36 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/01 20:53:09 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp" 
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
	std::cout << "Intern default constructeur called." << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
	return (*this);
	std::cout << "Intern assignment has been called." << std::endl;
	return (*this);
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern copy assignment has been called." << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern " << "has been destroyed." << std::endl;
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	std::string formType[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*	(Intern::*functionArray[])(std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formType[i] == formName)
		{
			std::cout << GREEN <<  "Intern " << "creates " << formName << "." << RESET << std::endl;
			return ((this->*functionArray[i])(target));
		}
	}
	std::cerr << RED << "Unknown form name, the form cannot be created!" << RESET << std::endl;
	return (NULL);
}

AForm	*Intern::makeShrubbery(std::string target)
{
	AForm	*form = new ShrubberyCreationForm(target);

	return (form);
}

AForm	*Intern::makeRobotomy(std::string target)
{
	AForm	*form = new RobotomyRequestForm(target);

	return (form);
}
AForm	*Intern::makePresidential(std::string target)
{
	AForm	*form = new PresidentialPardonForm(target);

	return (form);
}
