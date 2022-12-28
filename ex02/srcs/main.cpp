/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:06:51 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/29 00:20:42 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main()
{
	try
	{
		// Bureaucrat bureaucrat("nop", 155); // error cace
		Bureaucrat bureaucrat("nop", 150);
		ShrubberyCreationForm form1("nfukuma");
		RobotomyRequestForm form2("nfukuma");
		PresidentialPardonForm form3("nfukuma");

		std::cout << "sign check" << std::endl;
		bureaucrat.signForm(form1);
		bureaucrat.signForm(form2);
		bureaucrat.signForm(form3);
		std::cout << std::endl;

		// for (int i = 155; i > 0; i -= 5) // error cace
		for (int i = 150; i > 0; i -= 5)
		{
			bureaucrat.setGrade(i);
			std::cout << "\e[33mForm 1 ( Shrubbery )\e[m" << std::endl;
			bureaucrat.signForm(form1);
			bureaucrat.executeForm(form1);
			std::cout << "\e[31mForm 2 ( Robotomy )\e[m" << std::endl;
			bureaucrat.signForm(form2);
			bureaucrat.executeForm(form2);
			std::cout << "\e[32mForm 3 ( President )\e[m" << std::endl;
			bureaucrat.signForm(form3);
			bureaucrat.executeForm(form3);
			std::cout << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
