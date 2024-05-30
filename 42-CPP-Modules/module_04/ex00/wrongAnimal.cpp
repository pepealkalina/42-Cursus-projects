/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:47:48 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:46:17 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->type = "default";
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "Overload assignation operator called" << std::endl;
    this->type = src.type;
    return(*this);
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::setType(std::string srctype)
{
    this->type = srctype;
}

std::string WrongAnimal::getType(void)
{
    return(this->type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "wrong" << this->type << " made a sound" << std::endl;
}