/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:10:06 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/26 12:43:13 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>

# include <algorithm>
# include <stack>

class RPN
{
private:
    std::stack<int> rpnVector;
    int result;
public:
    RPN();
    RPN(RPN const &src);
    RPN &operator=(RPN const &src);

    void addElements(char *rpnSequence);
    
    //operators rpn
    void add();
    void subtract();
    void multiply();
    void divide();

    int getResult();
    
    ~RPN();
};


#endif