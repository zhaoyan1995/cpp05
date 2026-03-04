/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:20:05 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/03 17:59:07 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void):_name("Default name"),_grade(150)
{
    //std::cout << "Bureaucrat default constructeur called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name),_grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    this->_grade = grade;
    //std::cout << this->_name << " has been created with grade " << this->_grade << "."<< std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if (this == &src)
        return (*this);
    this->_grade = src._grade;
    //std::cout << "Bureaucrat assignment has been called." << std::endl;
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src):_name(src._name),_grade(src._grade)
{
   //std::cout << "Bureaucrat copy assignment has been called." << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    //std::cout << "Bureaucrat " << this->_name << " has been destroyed." << std::endl;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << ORANGE << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << this->_name  << " executed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << ORANGE << e.what() << RESET << std::endl;
	}
}

std::string Bureaucrat::getName(void)const
{
    return (this->_name);
}

int Bureaucrat:: getGrade(void)const
{
    return (this->_grade);
}

void    Bureaucrat::decrementGrade(void)
{
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();   
    this->_grade++;
}

void    Bureaucrat::incrementGrade(void)
{
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade--;
}

const   char *Bureaucrat::GradeTooHighException::what()const throw()
{
    return ("Bureaucrat: The grade is too high!");
}

const   char *Bureaucrat::GradeTooLowException::what()const throw()
{
    return ("Bureaucrat: The grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
    os << src.getName() << ", " << "bureaucrat grade " << src.getGrade() << "."  << std::endl;
    return (os);
}
