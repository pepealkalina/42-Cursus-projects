/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:12:15 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/09 18:25:44 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
private:
    Brain   *catBrain;
public:
    Cat(void);
    Cat(const Cat &copy);
    Cat &operator=(const Cat &src);
    ~Cat();

    void makeSound(void) const;

    /*Getters y setters*/
    void setType(std::string type);
    std::string getType(void);
};


#endif