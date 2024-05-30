/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:13:17 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/23 12:59:47 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
    if (argc > 1)
        PmergeMe(argv + 1);
    else
        std::cerr << "Error: wrong arguments" << std::endl;
    return 0;
}
