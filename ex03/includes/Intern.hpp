/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:41:52 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/29 00:09:44 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern
{
  private:
	Intern(const Intern &src);
	Intern &operator=(const Intern &rhs);

  public:
	Intern();
	~Intern();
	static AForm *makeForm(std::string name, std::string target);
};

#endif
