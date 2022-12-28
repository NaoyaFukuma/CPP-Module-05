/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:06:51 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/28 13:44:25 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		std::string form_name = "form no,";
		Bureaucrat bureaucrat("nfukuma", 2);
		// for (int i = 5; i >= 0; --i)
		for (int i = 5; i >= 1; --i)
		{
			Form form(form_name + std::to_string(i), i);
			std::cout << form << std::endl;
			bureaucrat.signForm(form);

		}

		// for (int i = 149; i < 155; ++i)
		for (int i = 148; i < 150; ++i)
		{
			Form form(form_name + std::to_string(i), i);
			std::cout << form << std::endl;
			bureaucrat.signForm(form);

		}



	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}
