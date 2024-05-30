/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:27:52 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 13:02:29 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap Name Constructor Called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ref)
{
    std::cout << "FragTrap overload assignation operator called" << std::endl;
    if (this != &ref)
        ClapTrap::operator=(ref);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << getName() << " want to do a high five!!" << std::endl;
}