/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:42:33 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/29 00:38:54 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

enum	forms
{
	ShrubberyCreation,
	RobotomyRequest,
	PresidentialPardon,
};

Intern::Intern()
{
}

Intern::~Intern()
{
}


AForm *Intern::makeForm(std::string name, std::string target)
{
	int	i;

	std::string Forms[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	i = 0;
	for (; i < 3 && Forms[i].compare(name); ++i)
		;
	AForm *res = nullptr;
	try
	{
		switch (i)
		{
			case ShrubberyCreation:
				res = new ShrubberyCreationForm(target); break;
			case RobotomyRequest:
				res = new RobotomyRequestForm(target); break;
			case PresidentialPardon:
				res = new PresidentialPardonForm(target); break;
			default:
				std::cout << "Intern cannot create " << name << " form" << std::endl;
		}
	}
	catch(const std::bad_alloc& ba)
	{
		std::cerr << ba.what() << '\n';
		std::exit(EXIT_FAILURE);
	}


	return (res);
}
