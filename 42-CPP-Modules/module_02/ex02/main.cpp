/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:10:07 by preina-g          #+#    #+#             */
/*   Updated: 2023/12/13 15:22:10 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(42.42f);
	
	std::cout << "operator ++" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "++a is: " << ++a << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "a++ is: " << a++ << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator --" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "--a is: " << --a << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "a-- is: " << a-- << std::endl;
	std::cout << "a is: " << a << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator +" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "c + b is: " << c + b << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator -" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "c - b is: " << c - b << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator *" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "c * b is: " << c * b << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator /" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "c / b is: " << c / b << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator >" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	if (c > b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator <" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	if (c < b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator >=" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	if (c >= b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator <=" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	if (c <= b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator ==" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	if (c == b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator !=" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	if (c != b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator max" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "max(c, b) is: " << Fixed::max(c, b) << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "operator min" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "min(c, b) is: " << Fixed::min(c, b) << std::endl;
	std::cout << "---------------------" << std::endl;

	return (0);
}
