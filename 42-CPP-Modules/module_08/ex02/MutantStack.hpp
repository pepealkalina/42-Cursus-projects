/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:01:36 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/12 11:51:07 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
    MutantStack(): std::stack<T>() {}
    
    //copy constructor
    MutantStack(MutantStack const &src): std::stack<T>(src)
    {
        *this = src;
    }
    
    //overload = 
    MutantStack &operator=(MutantStack const &src)
    {
        std::stack<T>::operator=(src);
        return(*this);
    }

    //this creates an intreator by the atraibute c that is a container_type
    typedef typename std::stack<T>::container_type::iterator iterator;

    //iterator begin
    iterator begin(void)
    {
        return (this->c.begin());
    }

    //iterator end
    iterator end(void)
    {
        return (this->c.end());
    }
    ~MutantStack() {}
};

#endif