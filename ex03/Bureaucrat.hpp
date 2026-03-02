/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:15:15 by yanzhao           #+#    #+#             */
/*   Updated: 2026/02/27 23:36:12 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <string>
#include <exception>

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		void	signForm(AForm &form);
		void	executeForm(AForm const &form)const;
		std::string getName(void)const;
		int getGrade(void)const;
		void	decrementGrade(void); //_grade++
		void	incrementGrade(void); //_grade--;

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();

		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif

