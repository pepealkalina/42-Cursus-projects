/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:47:01 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/25 17:58:59 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, const char **argv)
{
    BtcExchange btc;
    
    if (argc == 2)
    {
        btc.saveCsvData("./cpp_09/data.csv");
        btc.readFile(argv[1]);  
    }
    else
        std::cerr << "Error: wrong arguments" << std::endl;
    return 0;
}
