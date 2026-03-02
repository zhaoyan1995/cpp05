/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:00:55 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/01 20:45:09 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void):
_name("default aform name"),
_is_signed(false),
_gradeToSign(150),
_gradeToExecute(150)
{
	std::cout << "AForm default constructeur has been called." << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):
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
	std::cout << "An AForm named " << this->_name << " has been called." << std::endl;
}

AForm::AForm(const AForm &src):
_name(src._name),
_is_signed(src._is_signed),
_gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute)
{
	if (src._gradeToSign < 1)
	{
		throw (GradeTooHighException());
	}
	if (src._gradeToSign > 150)
	{
		throw (GradeTooLowException());
	}
	if (src._gradeToExecute < 1)
	{
		throw (GradeTooHighException());
	}
	if (src._gradeToExecute > 150)
	{
		throw (GradeTooLowException());
	}
	std::cout << "AForm copy constructor has been called." << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this == &src)
		return (*this);
	this->_is_signed = src._is_signed;
	std::cout << "AForm assignment has been called."	 << std::endl;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "An AForm named " << this->_name << " has been destroyed." << std::endl;
}

void	AForm::beSigned(Bureaucrat &person)
{
	if (person.getGrade() > this->get_gradeToSign())
		throw (GradeTooLowException());
	if (this->_is_signed == false)
	{
		this->_is_signed = true;
		std::cout << "this aform is signed by " << person.getName() << "." << std::endl;
	}
	else
		std::cout << "this aform has already been signed." << std::endl;
}

std::string AForm::getName(void)const
{
	return (this->_name);
}

bool	AForm::get_isSigned(void)const
{
	return (this->_is_signed);
}

int	AForm::get_gradeToSign(void)const
{
	return (this->_gradeToSign);
}

int	AForm::get_gradeToExecute(void)const
{
	return (this->_gradeToExecute);
}

const char *AForm::GradeTooLowException::what()const throw()
{
	return ("AForm: The level is too low!");
}

const char *AForm::GradeTooHighException::what()const throw()
{
	return ("AForm: The level is too high!");
}

const char *AForm::NotSignedException::what()const throw()
{
	return ("Form cannot be executed: It has not been signed yet!");
}

const char *AForm::NotExecutedException::what()const throw()
{
	return ("Execution denied: Executor's grade is too low!");
}

const char *AForm::FileOpenException::what()const throw()
{
	return ("File error: Outputfile cannot be created!");
}

std::ostream	&operator<<(std::ostream &os, const AForm &src)
{
	os << "AForm name: " << src.getName() << std::endl;
	os << "AForm signed? :";
	if (src.get_isSigned())
		os << "YES\n";
	else
		os << "NO\n";
	os << "grade to sign: " << src.get_gradeToSign() << std::endl;
	os << "grade to execute: " << src.get_gradeToExecute() << std::endl;
	return (os);
}
