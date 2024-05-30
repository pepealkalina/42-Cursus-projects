/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:04:05 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/28 13:25:06 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
    static_cast is used for casting variablesco se can turn a int to a char or a float to a int
*/


ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    (void)src;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    return(*this);
}

/*
    Output order
    
    char: Non displayable
    int: 0
    float: 0.0f
    double: 0.0
    
*/

void ScalarConverter::convert(std::string const &src)
{
    // +inff +inf
    if (src == "+inff" || src == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    // -inff -inf
    else if (src == "-inff" || src == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    // nan nanf
    else if (src == "nan" || src == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    else 
    {
        int _int;
        float _float;
        double _double;

        bool _isInt = true;
        bool _isFloat = true;
        bool _isDouble = true;
        // if there a literal char prints it
        if (src.size() == 1 && !std::isdigit(src[0]))
        {
            if (std::isprint(src[0]))
                std::cout << "char: " << static_cast<char>(src[0]) << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << static_cast<int>(src[0]) << std::endl;
            std::cout << "float: " << static_cast<float>(src[0]) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(src[0]) << ".0" << std::endl;
            return;
        }

        // check if the input can be an int
            _int = std::atoi(src.c_str());
        // check if the char can be printed with the int
        if (_int != -1 && std::isprint(_int))
            std::cout << "char: " << static_cast<char>(_int) << std::endl;
        else if ((_int != -1 && _int) && !std::isprint(_int))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        // print the int
        if (_int != -1 && _int)
		    std::cout << "int: " << _int << std::endl;
	    else
		    std::cout << "int: imposible" << std::endl;
        
        //check if the input is a float
        if (src[src.length() - 1] == 'f')
        {
            try
            {
                _float = static_cast<float>(std::atof(src.c_str()));
                _double = static_cast<double>(_float);
            }
            catch(const std::exception& e)
            {
                _isFloat = false;
            }    
        }
        else
        {
            try
            {
                _double = std::atof(src.c_str());
                _float = static_cast<float>(_double);
            }
            catch(const std::exception& e)
            {
                _isDouble = false;
            }    
        }
        if ((!_isFloat || !_float) || (!_isDouble || !_double)) 
	    {
	    	std::cout << "float: imposible" << std::endl;
	    	std::cout << "double: imposible" << std::endl;
	    	return;
	    }
        // check 
	    if (_float - static_cast<int>(_float) == 0) 
	    {
	    	std::cout << "float: " << _float << ".0f" << std::endl;
	    	std::cout << "double: " << _double << ".0" << std::endl;
	    } 
	    else 
	    {
	    	std::cout << "float: " << _float << "f" << std::endl;
	    	std::cout << "double: " << _double << std::endl;
	    }
    }
}

ScalarConverter::~ScalarConverter(){}	