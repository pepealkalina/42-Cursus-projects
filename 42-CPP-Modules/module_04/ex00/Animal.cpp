/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:47:48 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:28:43 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal constructor called" << std::endl;
    this->type = "default";
}
Animal::Animal(const Animal &copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}
Animal &Animal::operator=(const Animal &src)
{
    std::cout << "Overload assignation operator called" << std::endl;
    this->type = src.type;
    return(*this);
}
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::setType(std::string srctype)
{
    this->type = srctype;
}

std::string Animal::getType(void)
{
    return(this->type);
}

void Animal::makeSound(void) const
{
    std::cout << this->type << " made a sound" << std::endl;
}