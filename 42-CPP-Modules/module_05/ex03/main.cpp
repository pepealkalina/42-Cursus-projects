/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:00:37 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/28 09:44:48 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"
#include "Bureaucrat.hpp"
 
void ft_leaks()
{
	system("leaks -q Bureaucrat");
}

int main(void)
{
	atexit(ft_leaks);

	Bureaucrat a("Pepe", 1);
	Intern inter;

	std::cout << "------------------------" << std::endl;
	std::cout << "---Presidential test ---" << std::endl;
	std::cout << "------------------------" << std::endl;
	AForm *form1;
	try
	{
		form1 = inter.makeForm("PresidentialPardonForm", "bender");
		if (form1)
		{
			std::cout << *form1 << std::endl;
			a.executeForm(*form1);
			a.signForm(*form1);
			a.executeForm(*form1);
			delete form1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "---Robotomy test -------" << std::endl;
	std::cout << "------------------------" << std::endl;
	AForm *form2;
	try
	{
		form2 = inter.makeForm("RobotomyRequestForm", "bender");
		if (form2)
		{
			std::cout << *form2 << std::endl;
			a.executeForm(*form2);
			a.signForm(*form2);
			a.executeForm(*form2);
			delete form2;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "---Shrubbery test ------" << std::endl;
	std::cout << "------------------------" << std::endl;
	AForm *form3;
	try
	{
		form3 = inter.makeForm("ShrubberyCreationForm", "bender");
		if (form3)
		{
			std::cout << *form3 << std::endl;
			a.executeForm(*form3);
			a.signForm(*form3);
			a.executeForm(*form3);
			delete form3;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "---Unknown test --------" << std::endl;
	std::cout << "------------------------" << std::endl;
	AForm *form4;
	try
	{
		form4 = inter.makeForm("Unknow", "bender");
		if (form4)
		{
			std::cout << *form4 << std::endl;
			a.executeForm(*form4);
			a.signForm(*form4);
			a.executeForm(*form4);
			delete form4;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}