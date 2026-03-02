/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:24:09 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/01 20:54:02 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>

void	test_01(void)
{
	std::cout << "======Test 1 ShrubberyForm======\n" << std::endl;
	{
		Intern	amy;
		AForm	*form = NULL;

		form = amy.makeForm("shrubbery creation", "shrubbery");
		if (!form)
			return ;
		std::cout << *form;
		try	
		{
			Bureaucrat	Lily("Lily", 137);
			Lily.signForm(*form);
			Lily.executeForm(*form);
		}
		catch (std::exception &e)
		{
			std::cerr << ORANGE << "An error is occured: " << e.what() << RESET << std::endl;
		}
		if (form)
			delete form;
	}
	std::cout << "======Test 1======\n" << std::endl;
}

void	test_02(void)
{
	std::cout << "======Test 2 RobotomyRequestForm======\n" << std::endl;
	{
		Intern	amy;
		AForm	*form = NULL;

		form = amy.makeForm("robotomy request", "robotomy");
		if (!form)
			return ;
		std::cout << *form;
		try
		{
			Bureaucrat	Anne("Anne", 45);
			Anne.signForm(*form);
			Anne.executeForm(*form);
		}
		catch (std::exception &e)
		{
			std::cerr << ORANGE << "An error is occured: " << e.what() << RESET << std::endl;
		}
		if (form)
			delete form;
	}
	std::cout << "======Test 2======\n" << std::endl;
}

void	test_03(void)
{
	std::cout << "======Test 3 PresidentialPardonForm======\n" << std::endl;
	{
		Intern	jerry;
		AForm	*form = NULL;

		form = jerry.makeForm("presidential pardon", "presidential");
		if (!form)	
			return ;
		std::cout << *form;
		try
		{
			Bureaucrat	Jane("Jane", 5);
			Jane.signForm(*form);
			Jane.executeForm(*form);
		}
		catch (std::exception &e)
		{
			std::cerr << ORANGE << "An error is occured: " << e.what() << RESET << std::endl;
		}
		if (form)
			delete form;
	}
	std::cout << "======Test 3======\n" << std::endl;
}

void	test_04(void)
{
	std::cout << "======Test 4 Unknown form======\n" << std::endl;
	{
		Intern	hugo;
		AForm	*form = NULL;

		form = hugo.makeForm("Unknown form", "random target");
		if (!form)
			return ;
		std::cout << *form;
		try
		{
			Bureaucrat	Eric("Eric", 45);
			Eric.signForm(*form);
			Eric.executeForm(*form);
		}
		catch (std::exception &e)
		{
			std::cerr << ORANGE << "An error is occured: " << e.what() << RESET << std::endl;
		}
		if (form)
			delete form;
	}
	std::cout << "======Test 4======\n" << std::endl;
}

int	main(void)
{
	std::srand(std::time(0));
	test_01();
	test_02();
	test_03();
	test_04();

	return (0);
}
