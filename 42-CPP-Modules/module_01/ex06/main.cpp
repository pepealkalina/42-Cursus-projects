/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:26:09 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/12/05 13:54:36 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl Harl;
    int lebelNumber = -1;
    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 1;
    }
    std::string level[4] = {"DEBUG", "INFO", "WARNIG", "ERROR"};
    int i = 0;
    while (i < 4)
    {
        if (level[i] == argv[1])
        {
            lebelNumber = i;
            break;
        }
        else
            i++;
    }
    switch (lebelNumber)
    {
    case 0:
        Harl.complain("DEBUG");
        break;
    case 1:
        Harl.complain("INFO");
        break;
    case 2:
        Harl.complain("WARNIG");
        break;
    case 3:
        Harl.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
    return 0;
}
