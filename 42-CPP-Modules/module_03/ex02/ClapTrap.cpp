/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:41:53 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 11:28:42 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap name Constructor Called" << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
{
    std::cout << "ClapTrap overload assignation operator called" << std::endl;
    if (this != &ref)
    {
        this->_name = ref._name;
        this->_hitPoints = ref._hitPoints;
        this->_energyPoints = ref._energyPoints;
        this->_attackDamage = ref._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
    {
        std::cout << this->_name << " is out of energy points" << std::endl;
        return ;
    }
    else if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " is death can not attact" << std::endl;
        return ;
    }
    else
    {
        std::cout << this->_name << " attack with " << this->_attackDamage <<" attack damage to " << target << std::endl;
        this->_energyPoints--;
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Called" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << this->_name << " is death" << std::endl;
        return;   
    }
    this->_hitPoints -= amount;
    std::cout << this->_name << " take " << amount << " of damage." << " his hp = " << this->_hitPoints << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints == 0)
    {
        std::cout << this->_name << " is out of energy points" << std::endl;
        return ;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout << this->_name << " is death can not repair" << std::endl;
        return ;
    }
    else
    {
        this->_hitPoints += amount;
        this->_energyPoints--;
        std::cout << this->_name << " repaired " << amount << " of hp." << " his hp = " << this->_hitPoints << std::endl;
    }
}

std::string		ClapTrap::getName(void) const
{
    return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
    return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}