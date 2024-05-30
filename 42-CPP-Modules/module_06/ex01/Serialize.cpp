/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:15:42 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/28 13:44:40 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

/*
    reinterpret_cast is used to convert the pointer to any other type of pointer
*/

Serializer::Serializer() {}
Serializer::Serializer(Serializer const &src) 
{ 
    (void)src; 
}

Serializer &Serializer::operator=(Serializer const &src)
{
    (void)src;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
     return (reinterpret_cast<Data *>(raw));
}

Serializer::~Serializer() {}