/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:24:09 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/02 16:48:50 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

void	test_01(void)
{
	std::cout << "======Test 1======\n" << std::endl;
	{
		try
		{
			Bureaucrat bob("bob", 121);
			Form form("bob_form", 120, 100);
			std::cout << bob;
			std::cout << form;

			bob.signForm(form);
			std::cout << "\nAfter signForm function:\n" << form;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << "======Test 1======\n" << std::endl;
}

void	test_02(void)
{
	std::cout << "======Test 2======\n" << std::endl;
	{
		try
		{
			Bureaucrat tom("tom", 23);
			Form form("tom_form", 24,32);
			std::cout << tom;
			std::cout << "\n" << form;

			tom.signForm(form);
			std::cout << "\n" << form;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << "======Test 2======\n" << std::endl;
}

void	test_03(void)
{
	std::cout << "======Test 3 call the copy constructor======\n" << std::endl;
	{
		try
		{
			Bureaucrat alice("alice", 1);
			Form form("alice_form1", 32, 23);
			std::cout << alice;
			std::cout << "\n" << form;

			alice.signForm(form);
			std::cout << "\n" << form;

			Form copyForm(form);
			std::cout << "\ncopyForm: \n" << copyForm;
			alice.signForm(copyForm);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl; 
		}
	}
	std::cout << "======Test 3======\n" << std::endl;
}

void	test_04(void)
{
	std::cout << "Test 4: call the overload assignment" << std::endl;
	{
		try
		{
			Bureaucrat original("original", 45);
			Form form("original_form", 56, 12);
			std::cout << original;
			std::cout << "\n" << form;

			original.signForm(form);
			std::cout << "\n" << form;

			Form assignForm;
			assignForm = form;
			std::cout << "\n" << assignForm;
			original.signForm(assignForm);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl; 
		}
	}
	std::cout << "======Test 4======\n" << std::endl;
}

void	test_05(void)
{
	std::cout << "======Test 5======\n" << std::endl;
	{
		try
		{
			Form form1("form1", 151, 50);
			std::cout << "\n" << form1;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		try
		{
			Form form1("form1", 151, 50);
			std::cout << "\n" << form1;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

	}
	std::cout << "======Test 5======\n" << std::endl;
}

int	main(void)
{
	test_01();
	test_02();
	test_03();
	test_04();
	test_05();

	return (0);
}
