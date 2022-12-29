/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:06:51 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/29 12:23:13 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{

	{
		std::cout << "Intern class test" << std::endl;
		Intern someRandomIntern;
		AForm *rrf;
		// rrf = someRandomIntern.makeForm("robotomy", "Bender");
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
			std::cout << "Name[" << rrf->getName() << "] GradeToSign[" << rrf->getGradeToSign() << "] GradeToExecute [" << rrf->getGradeToExecute() << "]" << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
			std::cout << "Name[" << rrf->getName() << "] GradeToSign[" << rrf->getGradeToSign() << "] GradeToExecute [" << rrf->getGradeToExecute() << "]" << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
			std::cout << "Name[" << rrf->getName() << "] GradeToSign[" << rrf->getGradeToSign() << "] GradeToExecute [" << rrf->getGradeToExecute() << "]" << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("invalid form name", "Bender");
		if (rrf)
			std::cout << "Name[" << rrf->getName() << "] GradeToSign[" << rrf->getGradeToSign() << "] GradeToExecute [" << rrf->getGradeToExecute() << "]" << std::endl;
		delete rrf;
	}

	ShrubberyCreationForm form1("nfukuma");
	RobotomyRequestForm form2("nfukuma");
	PresidentialPardonForm form3("nfukuma");

	try
	{
		// Bureaucrat bureaucrat("nop", 155); // error cace
		// Bureaucrat bureaucrat("nop", 0); // error cace
		Bureaucrat bureaucrat("nop", 150);
		std::cout << "sign check" << std::endl;
		bureaucrat.signForm(form1);
		bureaucrat.signForm(form2);
		bureaucrat.signForm(form3);
		std::cout << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << '\n';
	}


	try
	{
		Bureaucrat bureaucrat("nop", 150);

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
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << '\n';
	}

}
