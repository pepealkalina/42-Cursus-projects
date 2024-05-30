/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:00:42 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/27 13:10:40 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    this->_grade = grade;
    if (_grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (_grade > 150)
        throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
    *this = src;
}

Bureaucrat const &Bureaucrat::operator=(const Bureaucrat &src)
{
    this->_name = src.getName();
    this->_grade = src.getGrade();
    return (*this);
}

// getters
const std::string Bureaucrat::getName() const 
{
    return(this->_name);
}

int Bureaucrat::getGrade() const
{
    return(this->_grade);
}

//Upgrade && Downgrade

void Bureaucrat::upGrade()
{
    this->_grade -= 1;
    if (_grade < 1)
        throw(Bureaucrat::GradeTooHighException());
}
void Bureaucrat::downGrade()
{
    this->_grade += 1;
    if (_grade > 150)
        throw(Bureaucrat::GradeTooLowException());
}

// Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("The grade is too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("The grade is too Low");
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " cannot execute " << form.getName() << " because "<< e.what() << '\n';
    }
    
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
    }
    
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

// Overloaded <<
std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    return(out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}