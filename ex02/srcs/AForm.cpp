/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:06:43 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/28 13:46:56 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(const std::string &name, int gradeToSign)
	: name_(name), gradeToSign_(gradeToSign), gradeToExecute_(0)
{
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src)
	: name_(src.getName()), gradeToSign_(src.getGradeToSign()),
		gradeToExecute_(src.getGradeToExecute())
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string &>(this->name_) = rhs.getName();
		this->signed_ = rhs.getSigned();
	}
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name_);
}

bool AForm::getSigned() const
{
	return (this->signed_);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign_);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute_);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign_)
		throw AForm::GradeTooLowException();
	this->signed_ = true;
}

void AForm::checkExecutable(const Bureaucrat &bureaucrat) const
{
	if (this->signed_ == false)
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > this->gradeToExecute_)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outstream, const AForm &rhs)
{
	outstream << "------------- AForm Info -------------" << std::endl;
	outstream << "AForm name: " << rhs.getName() << std::endl
		<< "Grade to sign: " << rhs.getGradeToSign() << std::endl
		<< "Grade to execute: " << rhs.getGradeToExecute();
	return (outstream);
}
