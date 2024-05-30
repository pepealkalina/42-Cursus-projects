/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:57:16 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/28 10:07:13 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();	
	ScalarConverter &operator=(ScalarConverter const &src);
public:
    static void convert(std::string const &src);
};


#endif