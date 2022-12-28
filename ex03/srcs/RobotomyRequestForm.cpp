/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:14:20 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/28 23:14:13 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), target_(src.target_)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
	(void)rhs;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	static int i;

	(void)executor;
	if (i % 2 == 0)
		std::cout << "BZZZZZT! " << target_ << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed! " << target_ << " is still alive." << std::endl;
	++i;
}
