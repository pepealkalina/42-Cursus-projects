/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:32 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/30 12:51:43 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BtcExchange::BtcExchange(){}

BtcExchange::BtcExchange(BtcExchange const &src)
{
    *this = src;
}

BtcExchange BtcExchange::operator=(BtcExchange const &src)
{
    this->btcData = src.btcData;
    return (*this);
}

static float parseCsvValue(std::string value)
{
    float fvalue = static_cast<float>(std::atof(value.c_str()));
    if (!fvalue)
        throw(std::runtime_error("Error: " + value + " not valid value"));
    return (fvalue);
}

static bool checkIfFloat(std::string value)
{
    int point = 0;
    int i;
    
    for (i = 0; i < value.length(); i++)
    {
        if (std::isdigit(value[i]) || value[i] == '.')
        {
            if (value[i] == '.')
                point++;
        }
        else
            break;
    }
    return (i == value.length() && point <= 1);
}

static float parseValue(std::string value)
{
    float fvalue = static_cast<float>(std::atof(value.c_str()));
    if (!checkIfFloat(value) || (fvalue < 0.0f || fvalue > 1000.0f))
        throw(std::runtime_error("Error: " + value + " not valid value"));
    return (static_cast<float>(std::atof(value.c_str())));
}

static void parseCsvDate(std::string date)
{

    std::string tempdate = date;
    int intDateArr[3];
    int i = 0;

    unsigned int delimPos = 0;
    while ((delimPos = tempdate.find('-')) != date.npos && i < 3)
    {
        intDateArr[i] = std::atoi(tempdate.substr(0, delimPos).c_str());
        // std::cout << intDateArr[i] << std::endl;
        tempdate.erase(0, delimPos + 1);
        i++;
    }
    //parse year
    if (intDateArr[0] != -1 && (intDateArr[0] < 2009 || intDateArr[0] > 2022))
        throw(std::runtime_error("Error: " + date + " not valid date"));
    if (intDateArr[1] != -1 && intDateArr[1] < 1 || intDateArr[1] > 12)
        throw(std::runtime_error("Error: " + date + " not valid date"));
    if (intDateArr[2] != -1 && intDateArr[2] >= 1 && intDateArr[2] <= 31)
    {
        if (intDateArr[1] == 2 && ((intDateArr[0] % 4 == 0 && intDateArr[0] % 100 != 0) || intDateArr[0] % 400 == 0))
        {
            if (intDateArr[2] > 29)
                throw std::runtime_error("Error: " + date + " not valid date");
        }
        else if (intDateArr[1] == 2 && intDateArr[2] > 28)
            throw std::runtime_error("Error: " + date + " not valid date");
    }
    else
        throw std::runtime_error("Error: " + date + " not valid date");
}

void BtcExchange::insertData(std::string date, float fvalue)
{
    this->btcData.insert(std::make_pair(date, fvalue));
}

void BtcExchange::saveCsvData(const char *file)
{
    std::string line;

    // data for parsing
    std::string date;
    std::string value;

    float fvalue;
    
    std::ifstream inputFile(file);
    
    if (inputFile.is_open())
        while (std::getline(inputFile, line, '\n'))
        {
            if (line == "date,exchange_rate")
                continue;
            try
            {
                date = line.substr(0, line.find(','));
                // std::cout << "date -> " << date << std::endl;
                parseCsvDate(date);
                value = line.substr(line.find(',') + 1, line.length() - 1);
                // std::cout << "value -> " << value << std::endl;
                fvalue = static_cast<float>(std::atof(value.c_str()));
                // std::cout << "fvalue -> " << fvalue << std::endl;
                insertData(date, fvalue);
                // std::cout << "map value -> " << this->btcData.find(date)->second << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
}

void BtcExchange::readFile(const char *file)
{
    std::map<std::string, float>::iterator it;
    
    std::string line;

    // data for parsing
    std::string date;
    std::string value;
    float fvalue;
    
    std::ifstream inputFile(file);
    
    if (inputFile.is_open())
        while (std::getline(inputFile, line, '\n'))
        {
            if (line == "date | value")
                continue; 
            try
            {
                date = line.substr(0, line.find('|') - 1);
                // std::cout << "date -> " << date << std::endl;
                parseCsvDate(date);
                value = line.substr(line.find('|') + 2, line.length());
                // std::cout << "value -> " << value << std::endl;
                fvalue = parseValue(value);
                std::cout << std::fixed << std::setprecision(2);
                std::cout << date \
                << " => " \
                << value \
                << " = ";
                if (this->btcData.find(date) == this->btcData.end())
                {
                    std::map<std::string, float>::iterator dateIt = --this->btcData.upper_bound(date);
                    std::cout << (fvalue * dateIt->second) << std::endl;
                }
                else
                    std::cout << (fvalue * this->btcData.find(date)->second) << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    else
        std::cerr << "Error: cant read file" << std::endl;
}

BtcExchange::~BtcExchange(){}

// >_<