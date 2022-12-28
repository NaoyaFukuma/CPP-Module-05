/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:16:01 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/28 23:05:51 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), target_(src.target_)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
	(void)rhs;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
	std::ofstream file(this->getName() + "_shrubbery");
	file << "                                                 " << std::endl;
	file << "                                  .         ;    " << std::endl;
	file << "     .              .              ;%     ;;     " << std::endl;
	file << "       ,           ,                :;%  %;      " << std::endl;
	file << "        :         ;                   :;%;'     ." << std::endl;
	file << ".        %;     %;            ;        %;'    ,; " << std::endl;
	file << " ;       ;%;  %%;        ,     %;    ;%;    ,%'  " << std::endl;
	file << "  %;       %;%;      ,  ;       %;  ;%;   ,%;'   " << std::endl;
	file << "   ;%;      %;        ;%;        % ;%;  ,%;'     " << std::endl;
	file << "    `%;.     ;%;     %;'         `;%%;.%;'       " << std::endl;
	file << "     `:;%.    ;%%. %@;        %; ;@%;%'          " << std::endl;
	file << "        `:%;.  :;bd%;          %;@%;'            " << std::endl;
	file << "          `@%:.  :;%.         ;@@%;'             " << std::endl;
	file << "            `@%.  `;@%.      ;@@%;               " << std::endl;
	file << "              `@%%. `@%%    ;@@%;                " << std::endl;
	file << "                ;@%. :@%%  %@@%;                 " << std::endl;
	file << "                  %@bd%%%bd%%:;                  " << std::endl;
	file << "                    #@%%%%%:;;                   " << std::endl;
	file << "                    %@@%%%::;                    " << std::endl;
	file << "                    %@@@%(o);  . '               " << std::endl;
	file << "                    %@@@o%;:(.,'                 " << std::endl;
	file << "                `.. %@@@o%::;                    " << std::endl;
	file << "                   `)@@@o%::;                    " << std::endl;
	file << "                    %@@(o)::;                    " << std::endl;
	file << "                   .%@@@@%::;                    " << std::endl;
	file << "                   ;%@@@@%::;.                   " << std::endl;
	file << "                  ;%@@@@%%:;;;.                  " << std::endl;
	file << "              ...;%@@@@@%%:;;;;,..               " << std::endl;
	file.close();
}
