/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:54:59 by preina-g          #+#    #+#             */
/*   Updated: 2023/12/14 13:03:23 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl; //default constructor
    this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl; //default copy constructor -> copy the value of fixed into this
    *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl; //default destructor
}

Fixed &Fixed::operator=(const Fixed &fixed)//overload the operator = to do the thing you want
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &fixed)
        this->fixed_point_value = fixed.getRawBits(); //check if fixed is the same as this, it is no the same, need to copy fixed into this an then return "this"
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point_value = raw;
}