/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:12:15 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:32:07 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
public:
    Cat(void);
    Cat(const Cat &copy);
    Cat &operator=(const Cat &src);
    ~Cat();

    void setType(std::string type);
    std::string getType(void);

    void makeSound(void) const;
};


#endif