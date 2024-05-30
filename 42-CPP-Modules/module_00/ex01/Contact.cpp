/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:27:32 by preina-g          #+#    #+#             */
/*   Updated: 2023/10/24 10:44:13 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

Contact::Contact()
{}

Contact::Contact(std::string FN, std::string LN, std::string NN, std::string PN, std::string DS)
{
    this->FirstName = FN;
    this->LastName = LN;
    this->NickName = NN;
    this->PhoneNumber = PN;
    this->Secret = DS;
}

Contact::~Contact()
{}

/*Add contact info functions*/
void Contact::add_FirstName(std::string str) //First Name
{
    this->FirstName = str;
}

void Contact::add_LastName(std::string str) //Last Name
{
    this->LastName = str;
}

void Contact::add_NickName(std::string str) //Nick Name
{
    this->NickName = str;
}

void Contact::add_PhoneNumber(std::string str) //Phone NUmber
{
    this->PhoneNumber = str;
}

void Contact::add_Secret(std::string str) //Secret
{
    this->Secret = str;
}

/*Get contact info functions*/

std::string Contact::get_FirstName(void) //First Name
{
    return(this->FirstName);
}

std::string Contact::get_LastName(void) //Last Name
{
    return(this->LastName);
}

std::string Contact::get_NickName(void) //Nick Name
{
    return(this->NickName);
}

std::string Contact::get_PhoneNumber(void) //Phone Number
{
    return(this->PhoneNumber);
}

std::string Contact::get_Secret(void) //Nick Name
{
    return(this->Secret);
}

