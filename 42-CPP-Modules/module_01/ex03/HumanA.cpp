/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:53:14 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/12/04 13:56:50 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): weapon(weapon)
{
    this->name = name;
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void)
{
    if (this->weapon.getType() == "")
    {
        std::cout << this->name << " can not attack, he/she is not armed" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}