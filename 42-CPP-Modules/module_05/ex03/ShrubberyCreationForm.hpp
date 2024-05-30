/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:58 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 12:59:18 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm ();
    ShrubberyCreationForm (std::string target);
    ShrubberyCreationForm (const ShrubberyCreationForm &src);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

    void execForm(Bureaucrat const &bureaucrat) const;\
    
    AForm *clone(std::string target);
    
    ~ShrubberyCreationForm ();

    // exec method
};

#endif