/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:24:09 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/02 17:49:53 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <exception>

void	test_01(void)
{
	std::cout << "======Test 1 ShrubberyForm======\n" << std::endl;
	{
		AForm *shrubberyForm = NULL;
		try
		{
			Bureaucrat bob("bob", 137);
			shrubberyForm = new ShrubberyCreationForm("shrubbery");
			std::cout << bob;
			std::cout << "\n" << *shrubberyForm;

			bob.signForm(*shrubberyForm);
			std::cout << "\n" << *shrubberyForm;

			bob.executeForm(*shrubberyForm);
			
			if (shrubberyForm)
			{
				delete shrubberyForm;
				shrubberyForm = NULL;
			}	
		}
		catch (std::exception &e)
		{
			if (shrubberyForm)
			{
				std::cerr << ORANGE << "An error is occured: " << e.what() << RESET << std::endl;
				delete shrubberyForm;
				shrubberyForm = NULL;
			}
		}
	}
	std::cout << "======Test 1======\n" << std::endl;
}

void	test_02(void)
{
	std::cout << "======Test 2 RobotomyForm======\n" << std::endl;
	{
		AForm *robotomyForm = NULL;
		try
		{
			Bureaucrat tom("tom", 45);
			robotomyForm = new RobotomyRequestForm("robotomy");
			std::cout << tom;
			std::cout << "\n" << *robotomyForm;

			tom.signForm(*robotomyForm);
			std::cout << "\n" << *robotomyForm;

			tom.executeForm(*robotomyForm);
			tom.executeForm(*robotomyForm);
			tom.executeForm(*robotomyForm);
			tom.executeForm(*robotomyForm);
			tom.executeForm(*robotomyForm);
			tom.executeForm(*robotomyForm);

			if (robotomyForm)
			{
				delete robotomyForm;
				robotomyForm = NULL;
			}
		}
		catch (std::exception &e)
		{
			if (robotomyForm)
			{
				std::cerr << ORANGE << "An error is occured: " << e.what() << RESET << std::endl; 
				delete robotomyForm;
				robotomyForm = NULL;
			}
		}
	}
	std::cout << "======Test 2======\n" << std::endl;
}

void	test_03(void)
{
	std::cout << "======Test 3 PresidentialPardonForm======\n" << std::endl;
	{
		AForm *presidentialForm = NULL;
		try
		{
			Bureaucrat alice("alice", 5);
			presidentialForm = new PresidentialPardonForm("presidential");
			std::cout << alice;
			std::cout << "\n" << *presidentialForm;

			alice.signForm(*presidentialForm);
			std::cout << "\n" << *presidentialForm;
		
			alice.executeForm(*presidentialForm);
			
			if (presidentialForm)
			{
				delete presidentialForm;
				presidentialForm = NULL;
			}
		}
		catch (std::exception &e)
		{
			if (presidentialForm)
			{
				std::cout << ORANGE << e.what() << RESET << std::endl; 
				delete presidentialForm;
				presidentialForm = NULL;
			}
		}
	}
	std::cout << "======Test 3======\n" << std::endl;
}

int	main(void)
{
	test_01();
	test_02();
	test_03();

	return (0);
}
