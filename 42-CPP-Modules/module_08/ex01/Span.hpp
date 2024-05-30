/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:41:33 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/11 17:45:47 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
private:
    unsigned int n;
    std::vector<int> _vec;
public:
    Span();
    Span(unsigned int size);
    Span(const Span &src);
    Span &operator=(const Span &src);

    //addnumber
    void addnumber(int number);
    
    class CanNotAddMoreNumbersException: public std::exception
    {
        public:
            virtual char const *what(void) const throw();
    };

    class ContainerIsNotLargeEnoughtException: public std::exception
    {
        public:
            virtual char const *what(void) const throw();
    };
    
    //span
    void shortestSpan();
    void longestSpan();
    
    //fill range
    void addRange(unsigned int range);
    
    ~Span();
};



#endif