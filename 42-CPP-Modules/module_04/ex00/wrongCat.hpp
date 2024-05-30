/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:12:15 by preina-g          #+#    #+#             */
/*   Updated: 2024/01/08 12:32:07 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "wrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
    WrongCat(void);
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &src);
    ~WrongCat();

    void setType(std::string type);
    std::string getType(void);

    void makeSound(void) const;
};


#endif