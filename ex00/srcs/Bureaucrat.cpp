/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:06:25 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/28 13:05:05 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: name_(name), grade_(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: name_(src.name_), grade_(src.grade_)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name_) = rhs.getName();
		this->grade_ = rhs.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name_);
}

int Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade_ - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--grade_;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade_ + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++grade_;
}

std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &rhs)
{
	outstream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (outstream);
}
