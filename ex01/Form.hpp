/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:27:38 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/03 17:05:58 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m" 
#define ORANGE   "\033[38;5;208m"

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
