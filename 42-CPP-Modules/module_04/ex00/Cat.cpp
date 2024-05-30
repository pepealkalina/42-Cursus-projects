/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:37:04 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:32:05 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}
Cat::Cat(const Cat &copy): Animal(copy)
{
    *this = copy;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Overload assignation operator called" << std::endl;
    this->type = src.type;
    return(*this);
}

Cat::~Cat()
{
   std::cout << "Cat destructor called" << std::endl; 
}

void Cat::setType(std::string type)
{
    this->type = type;
}

std::string Cat::getType(void)
{
    return(this->type);
}

void Cat::makeSound(void) const
{
    std::cout << "MEOOOOOOOOW" << std::endl;
}
