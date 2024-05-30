/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:56:22 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/09 18:34:08 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Overload Brain assignation operator called" << std::endl;
    if (&src != this)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    }
    return(*this);
}

void Brain::setIdea(std::string idea, int index)
{
    if (index >= 0 && index < 100)
    {
        std::cout << ideas[index] << std::endl;
        this->ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index)
{
    if (index >= 0 && index < 100)
        return(ideas[index]);
    return(ideas[0]);
}

