/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:19:07 by pepealkalin       #+#    #+#             */
/*   Updated: 2024/03/29 12:28:17 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(int argc, char const *argv[])
{
    char arr1[5] = "hola";
    int arr2[5] = {1, 2, 3, 4, 5};

    std::cout << "arr1 iter" << std::endl;
    iter(arr1, 5, print);
    std::cout << "arr2 iter" << std::endl;
    iter(arr2, 5, print);
    return 0;
}
