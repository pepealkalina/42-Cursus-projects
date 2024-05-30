/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:24:07 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:32:04 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}
Dog::Dog(const Dog &copy): Animal(copy)
{
    *this = copy;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Overload assignation operator called" << std::endl;
    this->type = src.type;
    return(*this);
}

Dog::~Dog()
{
   std::cout << "Dog destructor called" << std::endl; 
}

void Dog::setType(std::string type)
{
    this->type = type;
}

std::string Dog::getType(void)
{
    return(this->type);
}

void Dog::makeSound(void) const
{
    std::cout << "WOOFF" << std::endl;
}