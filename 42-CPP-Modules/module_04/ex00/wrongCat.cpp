/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:37:04 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:32:05 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    std::cout << "Overload assignation operator called" << std::endl;
    this->type = src.type;
    return(*this);
}

WrongCat::~WrongCat()
{
   std::cout << "WrongCat destructor called" << std::endl; 
}

void WrongCat::setType(std::string type)
{
    this->type = type;
}

std::string WrongCat::getType(void)
{
    return(this->type);
}

void WrongCat::makeSound(void) const
{
    std::cout << "wrong MEOOOOOOOOW" << std::endl;
}
