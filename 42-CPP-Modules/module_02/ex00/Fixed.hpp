/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:54:20 by preina-g          #+#    #+#             */
/*   Updated: 2023/12/12 12:21:40 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixed_point_value;
        static const int fractionalBits;
    public:
        Fixed(); //default constructor
        Fixed(const Fixed &fixed); //copy constructor
        ~Fixed(); //default destructor
        Fixed &operator=(const Fixed &fixed);//assignation operator overload
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif