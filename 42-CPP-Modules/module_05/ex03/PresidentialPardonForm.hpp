/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:50 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 12:55:47 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm ();
    PresidentialPardonForm (std::string target);
    PresidentialPardonForm (const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

    void execForm(Bureaucrat const &bureaucrat) const;

    ~PresidentialPardonForm ();

    AForm *clone(std::string target);
};

#endif