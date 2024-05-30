/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:35 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/26 10:00:27 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string _name;
    bool _isSigned;
    int _gradeToSign;
    int _gradeToExec;
public:
    AForm();
    AForm(const std::string name, int signGrade, int execGrade);
    AForm(const AForm &src);
    AForm const &operator=(const AForm &src);

    // Getters
    const std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    bool getIsSigned() const;
    
    // Sign methods
    void beSigned(Bureaucrat &bureaucrat);

    void execute(Bureaucrat const & executor) const;

    //abstracted method
    virtual void execForm(Bureaucrat const &bureaucrat) const = 0;
    virtual AForm *clone(std::string target) = 0;

    // Execptions
    class GradeTooHighException: public std::exception
    {
        public:
            virtual char const *what(void) const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
            virtual char const *what(void) const throw();
    };

    class FormIsNotSignedException: public std::exception
    {
        public:
            virtual char const *what(void) const throw();
    };
    virtual ~AForm();
};

std::ostream	&operator<<(std::ostream &out, AForm const &AForm);

#endif