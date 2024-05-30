/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:26:09 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/12/05 13:31:13 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl Harl;
    std::cout << "-DEBUG-" << std::endl;
    Harl.complain("DEBUG");
    std::cout << "-INFO-" << std::endl;
    Harl.complain("INFO");
    std::cout << "-WARNIG-" << std::endl;
    Harl.complain("WARNIG");
    std::cout << "-ERROR-" << std::endl;
    Harl.complain("ERROR");
    std::cout << "-OTHER-" << std::endl;
    Harl.complain("PEPE");
    return 0;
}
