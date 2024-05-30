/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:01:48 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/29 12:26:30 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void print(T src)   
{
    std::cout << src << " -> elemet of the T array" << std::endl;
}

template<typename T>
void iter(T *array, int len, void(f)(T &))
{
    for (int i = 0; i < len; i++)
        f(array[i]);    
}


#endif