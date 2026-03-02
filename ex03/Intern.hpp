/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:15:15 by yanzhao           #+#    #+#             */
/*   Updated: 2026/03/01 20:29:35 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include <string>
#include <exception>

class	AForm;

class	Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm	*makeForm(std::string formName, std::string target);

	private:
		AForm	*makeShrubbery(std::string target);
		AForm	*makeRobotomy(std::string target);
		AForm	*makePresidential(std::string target);
};

#endif

