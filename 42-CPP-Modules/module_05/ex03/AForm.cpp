/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:38 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 10:36:29 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(const std::string name, int signGrade, int execGrade): _name(name), _isSigned(false)
{
    // grade to execute compare
    this->_gradeToExec = execGrade;
    
    if (_gradeToExec < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (_gradeToExec > 150)
        throw(Bureaucrat::GradeTooLowException());
    
    // grade to sign compare
    this->_gradeToSign = signGrade;
    
    if (_gradeToSign < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (_gradeToSign > 150)
        throw(Bureaucrat::GradeTooLowException());
}

AForm::AForm(const AForm &src)
{
    *this = src;
}

AForm const &AForm::operator=(const AForm &src)
{
    this->_name = src._name;
    this->_isSigned = src._isSigned;
    this->_gradeToSign = src._gradeToSign;
    this->_gradeToExec = src._gradeToExec;
    
    return (*this);
}
// Getters
const std::string AForm::getName() const
{
    return (this->_name);
}

int AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
    return (this->_gradeToExec);
}

bool AForm::getIsSigned() const
{
    return (this->_isSigned);
}

// Sign methods
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw(GradeTooLowException());
}

// Exec method
void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() <= this->_gradeToExec)
    {
        std::cout << executor.getName() << " execute " << this->_name << std::endl;
        execForm(executor);
    }
    else if (!this->_isSigned)
        throw(FormIsNotSignedException());
    else
        throw(GradeTooLowException());
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
    return("The grade is too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return("The grade is too Low");
}

const char *AForm::FormIsNotSignedException::what() const throw()
{
    return("The Form is not Signed");
}

std::ostream	&operator<<(std::ostream &out, AForm const &AForm)
{
    return(out << AForm.getName() << ", AForm sign grade: " << AForm.getGradeToSign() << " execute grade: " << AForm.getGradeToExec() << " is signed: " << AForm.getIsSigned());
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}