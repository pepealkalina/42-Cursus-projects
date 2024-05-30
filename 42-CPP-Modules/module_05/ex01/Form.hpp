/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:36:57 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/25 12:08:32 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string _name;
    bool _isSigned;
    int _gradeToSign;
    int _gradeToExec;
public:
    Form();
    Form(const std::string name, int signGrade, int execGrade);
    Form(const Form &src);
    Form const &operator=(const Form &src);

    // Getters
    const std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    bool getIsSigned() const;
    
    // Sign methods
    void beSigned(Bureaucrat &bureaucrat);

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
    
    ~Form();
};

std::ostream	&operator<<(std::ostream &out, Form const &form);


#endif