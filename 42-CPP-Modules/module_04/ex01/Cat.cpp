/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:37:04 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/09 18:44:53 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->catBrain = new Brain;
}
Cat::Cat(const Cat &copy): Animal(copy)
{
    this->catBrain = new Brain(*copy.catBrain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Overload assignation operator called" << std::endl;
    this->type = src.type;
    this->catBrain = src.catBrain;
    return(*this);
}

Cat::~Cat()
{
    std::cout << "DELETING BRAIN!!!!!" << std::endl;
    std::cout << this->catBrain << std::endl;
    delete this->catBrain;
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