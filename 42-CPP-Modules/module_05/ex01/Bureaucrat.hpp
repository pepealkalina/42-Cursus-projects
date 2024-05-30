/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:00:40 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/25 12:21:15 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat const &operator=(const Bureaucrat &src);

    // Getters
    const std::string getName() const;
    int getGrade() const;
    
    // Upgrade && downgrade
    void upGrade();
    void downGrade();

    // Sign methods
    void signForm(Form &form);
    
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
    
    ~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat);


#endif