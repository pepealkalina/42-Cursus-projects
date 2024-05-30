/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:56:39 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/29 11:28:34 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>

/*
    Dynamic_cast convert safely pointers and classes son we can convert to every side, if this fails it throws an exception std::bad_cast
*/

Base * generate(void)
{
    int token;
    
    srand((unsigned) time(NULL));
    token = rand() % 3;

    switch (token)
    {
    case 0:
        return (new A());
        break;
    case 1:
        return (new B());
        break;
    case 2:
        return (new C());
        break;
    default:
        std::cout << "Error: Can not create the Random Base Class" << std::endl;
        break;
    }
    return (NULL);
}

void identify(Base* p)
{
    try
    {
        if (dynamic_cast<A *>(p))
        std::cout << p <<" -> The pointer is type A" << std::endl;
    }
    catch(std::bad_cast e)
    {
        std::cout << p << " -> A bad cast" << std::endl;
    }
    try
    {
        if (dynamic_cast<B *>(p))
        std::cout << p << " -> The pointer is type B" << std::endl;
    }
    catch(std::bad_cast e)
    {
        std::cout << p << " -> B bad cast" << std::endl;
    }
    try
    {
        if (dynamic_cast<C *>(p))
        std::cout << p << " -> The pointer is type C" << std::endl;
    }
    catch(std::bad_cast e)
    {
        std::cout << p << " -> C bad cast" << std::endl;
    }
}

void identify(Base& p)
{
   try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << &p << " -> The pointer is type A" << std::endl;
    }
    catch(std::bad_cast e)
    {
        std::cout << &p << " -> A bad cast" << std::endl;
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        std::cout << &p << " -> The pointer is type B" << std::endl;
    }
    catch(std::bad_cast e)
    {
        std::cout << &p << " -> B bad cast" << std::endl;
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        std::cout << &p << " -> The pointer is type C" << std::endl;
    }
    catch(std::bad_cast e)
    {
        std::cout << &p << " -> C bad cast" << std::endl;
    }
}

int main(void)
{
    Base *base;
    Base *base1;
    Base *base2;
    
    base = generate();
    std::cout << "The Ramdom class 1 its created" << std::endl;
    std::cout << "----------------------------\n" << std::endl;

    std::cout << "Identify by pointer" << std::endl;
    std::cout << "----------------------------\n" << std::endl;
    identify(base);

    std::cout << "\nIdentify by refernce" << std::endl;
    std::cout << "----------------------------" << std::endl;
    identify(*base);

    base1 = generate();
    std::cout << "\nThe Ramdom class 2 its created" << std::endl;
    std::cout << "----------------------------\n" << std::endl;

    std::cout << "Identify by pointer" << std::endl;
    std::cout << "----------------------------\n" << std::endl;
    identify(base1);

    std::cout << "\nIdentify by refernce" << std::endl;
    std::cout << "----------------------------\n" << std::endl;
    identify(*base1);

    base2 = generate();
    std::cout << "\nThe Ramdom class 3 its created" << std::endl;
    std::cout << "----------------------------\n" << std::endl;

    std::cout << "Identify by pointer" << std::endl;
    std::cout << "----------------------------\n" << std::endl;
    identify(base2);

    std::cout << "\nIdentify by refernce" << std::endl;
    std::cout << "----------------------------\n" << std::endl;
    identify(*base2);

    delete base;
    delete base1;
    delete base2;
    
    return 0;
}
