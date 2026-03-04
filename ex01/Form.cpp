/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:00:55 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/03 17:09:34 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void):
_name("default form name"),
_is_signed(false),
_gradeToSign(150),
_gradeToExecute(150)
{
	//std::cout << "Form default constructeur has been called." << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):
_name(name),
_is_signed(false),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1)
	{
		throw (GradeTooHighException());
	}
	if (gradeToSign > 150)
	{
		throw (GradeTooLowException());
	}
	if (gradeToExecute < 1)
	{
		throw (GradeTooHighException());
	}
	if (gradeToExecute > 150)
	{
		throw (GradeTooLowException());
	}
	//std::cout << "A Form named " << this->_name << " has been called." << std::endl;
}

Form::Form(const Form &src):
_name(src._name),
_is_signed(src._is_signed),
_gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute)
{
	//std::cout << "Form copy constructor has been called." << std::endl;
}

Form &Form::operator=(const Form &src)
{
	if (this == &src)
		return (*this);
	this->_is_signed = src._is_signed;
	//std::cout << "Form assignment has been called."	 << std::endl;
	return (*this);
}

Form::~Form(void)
{
	//std::cout << "A Form named " << this->_name << " has been destroyed." << std::endl;
}

void	Form::beSigned(Bureaucrat &person)
{
	if (person.getGrade() > this->get_gradeToSign())
		throw (GradeTooLowException());
	if (this->_is_signed == false)
		this->_is_signed = true;
	else
		std::cout << RED << "this form has already been signed." << RESET << std::endl;
}

std::string Form::getName(void)const
{
	return (this->_name);
}

bool	Form::get_isSigned(void)const
{
	return (this->_is_signed);
}

int	Form::get_gradeToSign(void)const
{
	return (this->_gradeToSign);
}

int	Form::get_gradeToExecute(void)const
{
	return (this->_gradeToExecute);
}

const char *Form::GradeTooLowException::what()const throw()
{
	return ("Form: The level is too low!");
}

const char *Form::GradeTooHighException::what()const throw()
{
	return ("Form: The level is too high!");
}

std::ostream	&operator<<(std::ostream &os, const Form &src)
{
	os << "Form name: " << src.getName() << std::endl;
	os << "Form signed? :";
	if (src.get_isSigned())
		os << "YES\n";
	else
		os << "NO\n";
	os << "grade to sign: " << src.get_gradeToSign() << std::endl;
	os << "grade to execute: " << src.get_gradeToExecute() << std::endl;
	return (os);
}
