/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:43:50 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 10:38:12 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(const std::string name, int signGrade, int execGrade): _name(name), _isSigned(false)
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

Form::Form(const Form &src)
{
    *this = src;
}

Form const &Form::operator=(const Form &src)
{
    this->_name = src._name;
    this->_isSigned = src._isSigned;
    this->_gradeToSign = src._gradeToSign;
    this->_gradeToExec = src._gradeToExec;
    
    return (*this);
}
// Getters
const std::string Form::getName() const
{
    return (this->_name);
}

int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
    return (this->_gradeToExec);
}

bool Form::getIsSigned() const
{
    return (this->_isSigned);
}

// Sign methods
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw(GradeTooLowException());
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
    return("The grade is too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return("The grade is too Low");
}

std::ostream	&operator<<(std::ostream &out, Form const &form)
{
    return(out << form.getName() << ", form sign grade: " << form.getGradeToSign() << " execute grade: " << form.getGradeToExec() << " is signed: " << form.getIsSigned());
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}