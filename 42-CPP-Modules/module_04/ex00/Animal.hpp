/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:08:21 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:28:49 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal(void);
    Animal(const Animal &copy);
    Animal &operator=(const Animal &src);
    ~Animal();

    void setType(std::string srctype);
    std::string getType(void);

    virtual void makeSound(void) const;
};


#endif