/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:07:51 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/23 12:40:07 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    std::string command;
    PhoneBook PhoneBook;
    std::string *info;
    std::string index_str;
    std::cout << "----Welcome to Pepe's PhoneBook---" << std::endl;
    std::cout << "\nADD -> add a contact\nSEARCH -> Show contact list\nEXIT -> exit the PhoneBook\n" << std::endl;
    while (command != "EXIT")
    {
        std::cout << "---Insert a command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
            PhoneBook.add_Contact_to_List();
        else if (command == "SEARCH")
        {
            PhoneBook.print_chart();
            while (!std::cin.eof())
            {
                std::cout << "---Insert a index for show the contact info: ";
                if (std::getline(std::cin, index_str) && index_str != "")
                {
                    char *str = const_cast<char*>(index_str.c_str());
                    if (std::all_of(index_str.begin(), index_str.end(), ::isdigit)\
                        && ((index_str[0] >='0' && index_str[0] < '8') && index_str.size() == 1))
                    {
                        if (PhoneBook.print_contact(std::atoi(str)))
                            break;
                    }
                }
            }
        }
        if (std::cin.eof())
        {
            std::cout << std::endl;
			return (0);
        }
    }
    return 0;
}
