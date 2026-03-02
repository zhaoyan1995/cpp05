/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:24:09 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/01 20:30:57 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

void	test_01(void)
{
	std::cout << "Test 1: try to create Bureaucrat bob(\"bob\", 0)" << std::endl;
	{
		try
		{
			Bureaucrat bob("bob", 0);
			std::cout << bob;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "======Test 1======\n" << std::endl;
}

void	test_02(void)
{
	std::cout << "Test 2: try to create Bureaucrat tom(\"tom\", 151)" << std::endl;
	{	
		try
		{
			Bureaucrat tom("tom", 151);
			std::cout << tom;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "======Test 2======\n" << std::endl;
}

void	test_03(void)
{
	std::cout << "Test 3: try to create Bureaucrat alice(\"alice\", 1)" << std::endl;
	{	
		try
		{
			Bureaucrat alice("alice", 1);
			std::cout << alice;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "======Test 3======\n" << std::endl;
}

void	test_04(void)
{
	std::cout << "Test 4: try to create Bureaucrat louise(\"louise\", 150)" << std::endl;
	{
		try
		{
			Bureaucrat louise("louise", 150);
			std::cout << louise;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "======Test 4======\n" << std::endl;


}

void	test_05(void)
{
	std::cout << "Test 5: call the copy constructeur" << std::endl;
	{
		try
		{
			Bureaucrat original("original", 45);
			std::cout << original;
			Bureaucrat copy(original);
			std::cout << copy;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "======Test 5======\n" << std::endl;
}

void	test_06(void)
{
	std::cout << "Test 6: call the copy constructeur" << std::endl;
	{
		try
		{
			Bureaucrat original("original", 98);
			std::cout << original;
			Bureaucrat assign("assign", 47);
			std::cout << assign;
			assign = original;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "======Test 6======\n" << std::endl;


}

void	test_07(void)
{
	std::cout << "Test 7: increment test" << std::endl;
	{
		try
		{
			Bureaucrat amy("amy", 12);
			for (int i = 0; i < 150; i++)
			{
				std::cout << amy;
				amy.incrementGrade();
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "======Test 7======\n" << std::endl;
}

void	test_08(void)
{
	std::cout << "Test 8: decrement test" << std::endl;
	{
		try
		{
			Bureaucrat eric("eric", 139);
			for (int i = 0; i < 150; i++)
			{
				std::cout << eric;
				eric.decrementGrade();
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl; 
		}
	}
	std::cout << "======Test 8======" << std::endl;
}

int	main(void)
{
	test_01();
	test_02();
	test_03();
	test_04();
	test_05();
	test_06();
	test_07();
	test_08();

	return (0);
}
