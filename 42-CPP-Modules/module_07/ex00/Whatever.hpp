/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:50:02 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/29 11:55:12 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp;
    
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T &min(T &a, T &b)
{
    if (a < b)
        return(a);
    else
        return(b);
}

template <typename T>
T& max(T &a, T &b)
{
    if (a > b)
        return(a);
    else
        return(b);
}

#endif