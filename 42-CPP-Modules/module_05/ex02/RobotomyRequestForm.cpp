/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:46 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 10:29:24 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("defaut") {}

RobotomyRequestForm::RobotomyRequestForm (std::string target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &src)
{
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    AForm::operator=(src);
    this->_target = src._target;
    return (*this);
}

void RobotomyRequestForm::execForm(Bureaucrat const &bureaucrat) const
{
    int isRobot;
    srand((unsigned) time(NULL));
    isRobot = rand() % 2;
    if (isRobot)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm ()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}