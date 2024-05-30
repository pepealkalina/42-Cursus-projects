/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:52:25 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/30 18:04:33 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN &RPN::operator=(RPN const &src)
{
    this->rpnVector = src.rpnVector;
    return (*this);
}

void RPN::add()
{
    int a = this->rpnVector.top();
    this->rpnVector.pop();
    int b = this->rpnVector.top();
    this->rpnVector.pop();

    this->result = a + b;
    this->rpnVector.push(this->result);
}
    
void RPN::subtract()
{
    int a = this->rpnVector.top();
    this->rpnVector.pop();
    int b = this->rpnVector.top();
    this->rpnVector.pop();

    this->result = b - a;
    this->rpnVector.push(this->result);
}

void RPN::multiply()
{
    int a = this->rpnVector.top();
    this->rpnVector.pop();
    int b = this->rpnVector.top();
    this->rpnVector.pop();

    this->result = a * b;
    this->rpnVector.push(this->result);
}

void RPN::divide()
{
    int a = this->rpnVector.top();
    this->rpnVector.pop();
    int b = this->rpnVector.top();
    this->rpnVector.pop();
    
    if (a == 0 || b == 0)
    {
        std::cerr << "Can not divide by 0" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->result = b / a;
    this->rpnVector.push(this->result);
}

static bool is_number(const std::string& s)
{
    unsigned int it = 0;
    while (it < s.size() && std::isdigit(s[it])) 
        it++;
    return !s.empty() && it == s.size();
}

static int is_sign(std::string sign)
{
    std::string signs[4] = {"+", "-", "*", "/"};

    int i = 0;
    while (i < 4)
    {
        if (sign == signs[i])
            return i;
        i++;
    }
    return -1;
}

void RPN::addElements(char *rpnSequence)
{
    std::string tmpStr;
    int strIt;


    // convert the rpnSquence to string for easy spliting;
    for (size_t x = 0; x < std::strlen(rpnSequence); x++) { 
		tmpStr = tmpStr + rpnSequence[x]; 
	}

    //split the string and add to a vector for calculation
    unsigned int delimPos = 0;
    int i = 0;
    int len = 0;
    // calculate len without spaces
    while (rpnSequence[i])
    {
        if (rpnSequence[i] != ' ')
            len++;
        i++;
    }

    if (len < 2)
        throw(std::runtime_error("ERROR: Wrong format"));
    
    std::string temp[len];
    i = 0;
    while ((delimPos = tmpStr.find(' ')) != tmpStr.npos && i < len)
    {
        temp[i] = tmpStr.substr(0, delimPos);
        tmpStr.erase(0, delimPos + 1);
        i++;
    }
    //start the calulation
    for (strIt = 0; strIt < len; strIt++)
    {
        //if the elemet is a number push to the vector
        int sign = is_sign(temp[strIt]);
        if (!is_number(temp[strIt]) && sign == -1)
            throw(std::runtime_error("ERROR"));
        
        if (is_number(temp[strIt]))
            this->rpnVector.push(std::atoi(temp[strIt].c_str()));            
        
        //cheack if element is a sign and do the operation
        else if (rpnVector.size() == 1 && sign != -1)
            throw(std::runtime_error("ERROR"));
        else if (rpnVector.size() == 2 && sign == -1)
            throw(std::runtime_error("ERROR"));
        else if (sign != -1)
        {
            switch (sign)
            {
            case 0:
                add();
                break;
            case 1:
                subtract();
                break;
            case 2:
                multiply();
                break;
            case 3:
                divide();
                break;
            default:
                std::cerr << "error not sign found" << std::endl;
                break;
            }
        }
    }
}

int RPN::getResult()
{    
    return(this->result);
}

RPN::~RPN()
{
}