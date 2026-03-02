/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:58:22 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/01 17:25:16 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP 
#include <string>
#include <fstream>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const  RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const  RobotomyRequestForm &src);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const &executor)const;

	private:
		std::string _target;
};

#endif

