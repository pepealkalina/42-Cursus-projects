/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:41:27 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 13:17:31 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    AForm *forms[3];
public:
    Intern();
    Intern(const Intern &src);
    Intern &operator=(const Intern &src);
    ~Intern();
    
    AForm *makeForm(std::string form, std::string target);

    class FormNameNotExist: public std::exception
    {
        public:
            virtual char const *what(void) const throw();
    };
};

#endif