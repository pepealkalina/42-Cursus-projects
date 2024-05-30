/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:56:42 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/12/04 13:56:25 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    this->type = str;
}

Weapon::~Weapon()
{
}

std::string &Weapon::getType(void)
{
    return(this->type);
}

void    Weapon::setType(std::string str)
{
    this->type = str;
}
