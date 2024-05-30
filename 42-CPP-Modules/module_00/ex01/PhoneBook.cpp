/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:27:35 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/23 12:14:50 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "----Closing Pepe's PhoneBook---" << std::endl;
}

void PhoneBook::print_chart(void)
{
    std::cout << " __________ __________ __________ __________ \n\
|Index     |First name|Last Name |Nick Name |\n\
|__________|__________|__________|__________|" << std::endl;
    int i = 0;
    while (i < (this->index % 8))
    {
        std::cout << "|";
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << i << "|";
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << this->ContactList[i].get_FirstName().substr(0, 10) << "|";
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << this->ContactList[i].get_LastName().substr(0, 10) << "|";
        if (i == ((this->index % 8) - 1))
        {
            std::cout << std::setfill(' ') << std::setw(9);
            std::cout << this->ContactList[i].get_NickName().substr(0, 9) << ".|" << std::endl;
        }
        else
        {
            std::cout << std::setfill(' ') << std::setw(10);
            std::cout << this->ContactList[i].get_NickName().substr(0, 10) << "|" << std::endl;
        }
        i++;
    }
    std::cout << "|__________|__________|__________|__________|\n" << std::endl;
}

int PhoneBook::print_contact(int index)
{
    if (this->ContactList[index].get_FirstName().size())
    {
        std::cout << "\n---Showing " << this->ContactList[index].get_FirstName() << "'s info---\n" << std::endl;
        print_contact_info(this->ContactList[index]);
        std::cout << std::endl;
    }
    else
    {
        std::cout << "\nError! There is not info abot this contact" << std::endl;
        return (0);
    }
    return (1);
}

void PhoneBook::print_contact_info(Contact contact)
{
    std::cout << "-First Name: " << contact.get_FirstName() << std::endl;
    std::cout << "-Last Name: " << contact.get_LastName() << std::endl;
    std::cout << "-Nick Name: " << contact.get_NickName() << std::endl;
    std::cout << "-Phone Number " << contact.get_PhoneNumber() << std::endl;
    std::cout << "-Darkest Secret: " << contact.get_Secret() << std::endl;
}

void PhoneBook::add_Contact_to_List(void)
{
    std::string *info;
    if (this->index > 7)
        std::cout << "Overwriting info in: " << this->ContactList[this->index % 8].get_FirstName() << std::endl;
    info = add_Contact_info();
    std::cout << std::endl;
    Contact temp(info[0], info[1], info[2], info[3], info[4]);  
    this->ContactList[this->index % 8] = temp;
    this->index++;
}

std::string *add_Contact_info(void)
{
    static std::string hola[5];
    std::string str;    
    std::cout << std::endl;
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "-Insert First Name: ";
        if (std::getline(std::cin, str) && str != "")
            hola[0] = str;
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "-Insert Last Name: ";
        if (std::getline(std::cin, str) && str != "")
            hola[1] = str;
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "-Insert Nick Name: ";
        if (std::getline(std::cin, str) && str != "")
            hola[2] = str;
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "-Insert Phone Number: ";
        if (std::getline(std::cin, str) && str != "")
            hola[3] = str;
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "-Insert Darkest Secret: ";
        if (std::getline(std::cin, str) && str != "")
            hola[4] = str;
    }
    return(hola);
}
