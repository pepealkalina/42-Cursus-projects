/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:31:45 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/01/08 12:50:28 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::string name = "mama la pepea";
    Zombie *zombie = zombieHorde(13, name);
    int i = 0;
    
    while(i < 13)
    {
        zombie[i].announce();
        i++;
    }
    delete zombie;
}