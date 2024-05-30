/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:35:13 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/28 13:44:31 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

/* uintptr_t its the same as void * so we can us reinterpret_cast to casting it*/
int main( void )
{
	Data		original;
	uintptr_t	serial;
	Data *		modified;

	original.str = "hola mundo";
	original.number = 25;
	serial = Serializer::serialize(&original);
	modified = Serializer::deserialize(serial);
    
	std::cout << "-----------------------" << std::endl;
	std::cout << "---- Original data ----" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "str:     " << original.str << std::endl;
	std::cout << "number:  " << original.number << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "--- Serialized data ---" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "serial:  " << serial << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "---- Modified data ----" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Address: " << modified << std::endl;
	std::cout << "str:     " << modified->str << std::endl;
	std::cout << "number:  " << modified->number << std::endl;
	std::cout << std::endl;
	
	return (0);
}