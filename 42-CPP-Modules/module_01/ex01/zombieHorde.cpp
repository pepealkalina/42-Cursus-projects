/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:36:44 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/11/30 13:19:21 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N,std::string name)
{
    Zombie *zombieHorde = new Zombie[N];
    int i = 0;

    while(i < N)
    {
        zombieHorde[i] = Zombie(name);
        i++;
    }
    return (zombieHorde);
}