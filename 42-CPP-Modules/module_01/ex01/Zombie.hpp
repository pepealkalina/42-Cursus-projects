/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:57:53 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/11/30 13:28:00 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    Zombie(void);
    ~Zombie(void);
    void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif