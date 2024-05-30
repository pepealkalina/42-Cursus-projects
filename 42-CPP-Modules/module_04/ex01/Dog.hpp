/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:43:59 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/09 18:25:37 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
private:
    Brain   *dogBrain;
public:
    Dog(void);
    Dog(const Dog &copy);
    Dog &operator=(const Dog &src);
    ~Dog();

    void makeSound(void) const;

    /*Getter and setters*/
    void setType(std::string type);
    std::string getType(void);
};


#endif