/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:24:59 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/12/04 11:39:02 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    /*print mem addr*/
    std::cout << "Memory addres of str -> " << &str << std::endl;
    std::cout << "Memory addres of stringPTR -> " << stringPTR << std::endl;
    std::cout << "Memory addres of stringREF -> " << &stringREF << std::endl;

    /*print value*/
    std::cout << "Memory value of str -> " << str << std::endl;
    std::cout << "Memory value of stringPTR -> " << *stringPTR << std::endl;
    std::cout << "Memory value of stringREF -> " << stringREF << std::endl;
    
    return 0;
}
