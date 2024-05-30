/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:35:18 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/10 16:44:17 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class ElementNotFoundException: public std::exception
    {
        public:
            virtual char const *what(void) const throw()
            {
                return("The element to find doesn't exists.");
            }
    };

template <typename T>
typename T::iterator easyfind(T &src, int toFind)
{
    typename T::iterator i;
    if ((i = std::find(src.begin(), src.end(), toFind)) != src.end())
        return (i);
    else
        throw(ElementNotFoundException());
}


#endif