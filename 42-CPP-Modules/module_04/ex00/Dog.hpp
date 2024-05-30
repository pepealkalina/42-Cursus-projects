/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:43:59 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:31:50 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
public:
    Dog(void);
    Dog(const Dog &copy);
    Dog &operator=(const Dog &src);
    ~Dog();

    void setType(std::string type);
    std::string getType(void);

    void makeSound(void) const;
};


#endif