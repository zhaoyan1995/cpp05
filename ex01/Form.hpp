/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:27:38 by yanzhao           #+#    #+#             */
/*   Updated: 2026/02/27 19:16:56 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form(void);

		void	beSigned(Bureaucrat &person);

		std::string getName(void)const;
		bool	get_isSigned(void)const;
		int	get_gradeToSign(void)const;
		int	get_gradeToExecute(void)const;

	class	GradeTooHighException: public std::exception
	{
		public:
			virtual const char *what()const throw();
	};

	class	GradeTooLowException: public std::exception
	{
		public:
			virtual const char *what()const throw();
	};

	private:
		const std::string _name;
		bool	_is_signed;
		const int	_gradeToSign;
		const int	_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &os, const Form &src);

#endif
