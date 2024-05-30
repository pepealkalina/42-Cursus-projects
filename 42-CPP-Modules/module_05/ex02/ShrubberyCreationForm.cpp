/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:56 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 10:29:47 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("defaut") {}

ShrubberyCreationForm::ShrubberyCreationForm (std::string target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm &src)
{
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    AForm::operator=(src);
    this->_target = src._target;
    return (*this);
}

void ShrubberyCreationForm::execForm(Bureaucrat const &bureaucrat) const
{
    std::ofstream out;
    std::string fileName = this->_target + "_shrubbery";

    out.open(fileName);
    if (!out)
    {
       std::cerr << "Error: file could not be opened" << std::endl;
       return ; 
    }
    else
        out << "                                         .\n \
                                              .         ;  \n \
                 .              .              ;%     ;;  \n \
                   ,           ,                :;%  %;   \n \
                    :         ;                   :;%;'     ., \n \
           ,.        %;     %;            ;        %;'    ,;\n \
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n \
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n \
               ;%;      %;        ;%;        % ;%;  ,%;'\n \
                `%;.     ;%;     %;'         `;%%;.%;'\n \
                 `:;%.    ;%%. %@;        %; ;@%;%'\n \
                    `:%;.  :;bd%;          %;@%;'\n \
                      `@%:.  :;%.         ;@@%;'\n \
                        `@%.  `;@%.      ;@@%; \n \
                          `@%%. `@%%    ;@@%;  \n \
                            ;@%. :@%%  %@@%; \n \
                              %@bd%%%bd%%:; \n \
                                #@%%%%%:;;\n \
                                %@@%%%::;\n \
                                %@@@%(o);  . ' \n \
                                %@@@o%;:(.,'\n \
                            `.. %@@@o%::;\n \
                               `)@@@o%::;\n \
                                %@@(o)::;\n \
                               .%@@@@%::;\n \
                               ;%@@@@%::;.\n \
                              ;%@@@@%%:;;;.\n \
                          ...;%@@@@@%%:;;;;,..\n" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm ()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}