/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:19:43 by preina-g          #+#    #+#             */
/*   Updated: 2023/10/25 11:56:27 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string Secret;
    public:
        Contact(void);
        Contact(std::string FN, std::string LN, std::string NN, std::string PN, std::string DS);
        ~Contact(void);
        /*index num*/
        int index;
        /*add contact info*/
        void add_FirstName(std::string str);
        void add_LastName(std::string str);
        void add_NickName(std::string str);
        void add_PhoneNumber(std::string str);
        void add_Secret(std::string str);
        /*get contact info for search*/
        std::string get_FirstName(void);
        std::string get_LastName(void);
        std::string get_NickName(void);
        std::string get_PhoneNumber(void);
        std::string get_Secret(void);
};

class PhoneBook
{
private:
    Contact ContactList[8];
    int index;
public:
    PhoneBook();
    ~PhoneBook();
    void add_Contact_to_List(void);
    void print_contact_info(Contact contact);
    int print_contact(int index);
    void print_chart(void);
};

std::string *add_Contact_info(void);

#endif