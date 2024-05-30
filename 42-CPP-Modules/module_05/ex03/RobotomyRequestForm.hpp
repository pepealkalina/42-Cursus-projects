/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:53 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 12:59:22 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm: public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm ();
    RobotomyRequestForm (std::string target);
    RobotomyRequestForm (const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

    void execForm(Bureaucrat const &bureaucrat) const;

    AForm *clone(std::string target);
    
    ~RobotomyRequestForm ();

    // exec method
};

#endif