/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:41:24 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 13:18:50 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    this->forms[0] = new PresidentialPardonForm();
    this->forms[1] = new RobotomyRequestForm();
    this->forms[2] = new ShrubberyCreationForm();
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return (*this);
}
    
AForm *Intern::makeForm(std::string form, std::string target)
{
    std::string formsName[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm *temp;
    int exist = 0;
    int formpos;
    
    for(int i = 0; i < 3; i++)
    {
        if (form == formsName[i])
        {
            exist = 1;
            formpos = i; //takes the form pos
            break;
        }
    }
    
    if (exist == 0)
        throw (FormNameNotExist());
    else
    {
        std::cout << "Intern creates " << form << std::endl;
        return (this->forms[formpos]->clone(target));
    }
}

char const *Intern::FormNameNotExist::what(void) const throw()
{
    return ("the form not exist");
}

Intern::~Intern()
{
    delete forms[0];
    delete forms[1];
    delete forms[2];
    std::cout << "Intern Destructor called" << std::endl;
}