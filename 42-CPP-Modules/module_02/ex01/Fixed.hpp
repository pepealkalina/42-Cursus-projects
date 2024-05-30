/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:26:39 by preina-g          #+#    #+#             */
/*   Updated: 2023/12/12 15:27:52 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits;
    public:
        Fixed(); //default constructor
        Fixed(const int num); //constructor from int
        Fixed(const float num); //constructor from float
        Fixed(const Fixed &fixed); //copy constructor
        ~Fixed(); //default destructor
        Fixed &operator=(const Fixed &fixed);//assignation operator overload
        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out,const Fixed &fixed);

#endif