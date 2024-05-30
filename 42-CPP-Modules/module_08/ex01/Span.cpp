/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:41:31 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/11 17:51:35 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    this->n = 0;
}
Span::Span(unsigned int size)
{
    this->n = size;
}
Span::Span(const Span &src)
{
    *this = src;
}
Span &Span::operator=(const Span &src)
{
    this->_vec = src._vec;
    this->n = src.n;

    return (*this);
}

//addnumber
void Span::addnumber(int number)
{
    if (this->_vec.size() >= this->n)
        throw(CanNotAddMoreNumbersException());
    else
        this->_vec.push_back(number);
}

void Span::addRange(unsigned int range)
{
    srand((unsigned) time(NULL));
    for (size_t i = 0; i < range; i++)
    {
        try
        {
            addnumber(rand());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            break;
        }
        
    }
    
}

char const *Span::CanNotAddMoreNumbersException::what() const throw()
{
    return("Can not add more Numbers");
}

char const *Span::ContainerIsNotLargeEnoughtException::what() const throw()
{
    return("The container is not too long to do the span");
}

void Span::longestSpan()
{
    if (this->n > 1)
    {    
        std::cout << "The longest span is " \
        << *std::max_element(this->_vec.begin(), this->_vec.end()) \
        - \
        *std::min_element(this->_vec.begin(), this->_vec.end())\
        << std::endl;    
    }
    else
        throw(ContainerIsNotLargeEnoughtException());
}
//span
void Span::shortestSpan()
{
    if (this->n > 1)
    {    
        std::sort(this->_vec.begin(), this->_vec.end());
        
        //create iterator && dif vector
        std::vector<int> difvec;
        std::vector<int>::iterator it;
        std::vector<int>::iterator difit;
        
        //iterate vector
        for (it = this->_vec.begin(); it < this->_vec.end(); it++)
        {
            // std::cout << "it-> " << *it << std::endl;
            for(difit = this->_vec.begin(); difit < this->_vec.end(); difit++)
            {
                if (difit != it && difit > it)
                {
                    // std::cout << "difit-> " << *difit << std::endl;
                    difvec.push_back(*difit - *it);
                    // std::cout << "dif-> " << *difit - *it << std::endl; 
                }
            }
        }

        std::cout << "The shortest span is " \
        << *std::min_element(difvec.begin(), difvec.end()) 
        << std::endl;
        
    }
    else
        throw(ContainerIsNotLargeEnoughtException());
}

Span::~Span()
{
    
}