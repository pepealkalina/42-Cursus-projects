/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:58 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/26 13:46:13 by pepealkalin      ###   ########.fr       */
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

    void execForm(Bureaucrat const &bureaucrat) const;

    ~ShrubberyCreationForm ();

    // exec method
};

#endif