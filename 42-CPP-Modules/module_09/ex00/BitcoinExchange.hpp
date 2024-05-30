/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:02:14 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/25 17:51:49 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>

# include <string>
//map container
# include <map>
# include <algorithm>


# include <stdexcept>
# include <fstream>

class BtcExchange
{
private:
    std::map<std::string, float> btcData;
public:
    BtcExchange();
    BtcExchange(BtcExchange const &src);
    BtcExchange operator=(BtcExchange const &src);
    
    //read file
    void readFile(const char *file);
    
    //save data from csv
    void saveCsvData(const char *file);

    std::string findNearestDate(std::string date);

    void insertData(std::string date, float fvalue);
    
    ~BtcExchange();
};

#endif