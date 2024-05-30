/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:30:55 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/09 11:53:40 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;
public:
    Array(): _size(0) //std constructor
    {
        this->_array = new T[0];
    }
    Array(unsigned int size): _size(size) // unsigned int constructor
    {
        this->_array = new T[size];
        for (unsigned int i = 0; i < size; i++)
            this->_array[i] = 0; //set all array to 0 to prevent memory fails
    }

    Array(Array const &src): _size(src.size()) // copy constructor
    {
        this->_array = NULL;
        *this = src;
    }
    
    Array const &operator=(Array const &src)
    {
        if (this->_array)
            delete [] this->_array;
        if (src.size())
        {
            this->_size = src.size();
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = 0;
        }
		return (*this);
        
    }
    
    unsigned int size() const
    {
        return (this->_size);
    }
    
    class IndexNotExistException: public std::exception
    {
        public:
            virtual char const *what(void) const throw()
            {
                return("The index is out of range");
            }
    };
    
    
    T &operator[](unsigned int index)
    {
        if (index >= this->_size)
            throw(IndexNotExistException());
        else
        {
            std::cout << "index -> " << index << std::endl;
        }
        return(this->_array[index]);
    }
    
    ~Array()
    {
        if (this->_array)
            delete [] this->_array;
    }
    
};

#endif