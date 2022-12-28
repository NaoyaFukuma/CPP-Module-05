/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:07:03 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/28 16:56:46 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class	Bureaucrat;

class AForm
{
  private:
	const std::string name_;
	bool signed_;
	const int gradeToSign_;
	const int gradeToExecute_;

	AForm();

  public:
	AForm(const std::string &name, int gradeToSign);
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &src);
	virtual ~AForm();

	AForm &operator=(const AForm &rhs);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
	void checkExecutable(const Bureaucrat &bureaucrat) const;

	virtual void execute(const Bureaucrat &executor) const = 0;
	/* ---------------- Exception Classes ---------------- */
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		}
	};
	class NotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Form not signed");
		}
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif // FORM_HPP
