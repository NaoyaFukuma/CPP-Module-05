/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:06:43 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/28 13:46:56 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign)
	: name_(name), gradeToSign_(gradeToSign), gradeToExecute_(0)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
	: name_(src.getName()), gradeToSign_(src.getGradeToSign()),
		gradeToExecute_(src.getGradeToExecute())
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name_) = rhs.getName();
		this->signed_ = rhs.getSigned();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->name_);
}

bool Form::getSigned() const
{
	return (this->signed_);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign_);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute_);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign_)
		throw Form::GradeTooLowException();
	this->signed_ = true;
}

std::ostream &operator<<(std::ostream &outstream, const Form &rhs)
{
	outstream << "------------- Form Info -------------" << std::endl;
	outstream << "Form name: " << rhs.getName() << std::endl
		<< "Grade to sign: " << rhs.getGradeToSign() << std::endl
		<< "Grade to execute: " << rhs.getGradeToExecute();
	return (outstream);
}
