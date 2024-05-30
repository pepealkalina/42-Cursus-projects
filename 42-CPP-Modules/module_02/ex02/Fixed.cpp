/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:26:32 by preina-g          #+#    #+#             */
/*   Updated: 2023/12/13 15:31:18 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl; //default constructor
    this->fixedPointValue = 0;
}

Fixed::Fixed(const int num)//
{
    //std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = num << this->fractionalBits; //save the int moving the bits fractionalsbits value times
}

Fixed::Fixed(const float num)//
{
    //std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(num * (1 << this->fractionalBits)); //save the float rounding it multiplyin num by the value of moving the bits of fractionalBits one time
}

Fixed::Fixed(const Fixed &fixed)
{
    //std::cout << "Copy constructor called" << std::endl; //default copy constructor -> copy the value of fixed into this
    *this = fixed;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl; //default destructor
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    //std::cout << "Assignation operator called" << std::endl;
    if (this != &fixed)
        this->fixedPointValue = fixed.getRawBits(); //check if fixed is the same as this, it is no the same, need to copy fixed into this an then return "this"
    return (*this);
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    //
    return(float(this->fixedPointValue) / float(1 << this->fractionalBits)); //reverse the integer dividing the value of fixedPointValue by the float that have moving all bits off fractionalBits one time
}

int Fixed::toInt(void) const
{
    return (this->fixedPointValue >> this->fractionalBits); //move the fixedPointValue bits to get the integer that is 8bits long
}

std::ostream &operator<<(std::ostream &out,const Fixed &fixed)
{
    out << fixed.toFloat();//overload << operator tu send output a float number and print it
    return(out);
}

/*OPERATORS*/

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->fixedPointValue > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->fixedPointValue < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->fixedPointValue >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->fixedPointValue <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->fixedPointValue == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->fixedPointValue != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    if (fixed.toFloat() == 0)
        return (Fixed(0));
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator++(void)
{
    this->fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator--(void)
{
    this->fixedPointValue--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
    if (num1 < num2)
        return (num1);
    return (num2);
}
Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
    if (num1 > num2)
        return (num1);
    return (num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
    if (num1 < num2)
        return (num1);
    return (num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
    if (num1 > num2)
        return (num1);
    return (num2);
}
