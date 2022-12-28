/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:07:03 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/28 13:11:59 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class	Bureaucrat;

class Form
{
  private:
	const std::string name_;
	bool signed_;
	const int gradeToSign_;
	const int gradeToExecute_;

	Form();

  public:
	Form(const std::string &name, int gradeToSign);
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &src);
	~Form();

	Form &operator=(const Form &rhs);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif // FORM_HPP
