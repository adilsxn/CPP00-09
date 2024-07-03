#include "../inc/BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

BitcoinExchange::BitcoinExchange(void):_databaseFile("data.csv"), _inputFile("helo"){
    return ;
}


BitcoinExchange::BitcoinExchange(std::string& inputFile):_inputFile(inputFile){
    return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src){
    *this = src;
    return ;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs){
    if (this != &rhs){
        this->_inputFile = rhs._inputFile;
        this->_databaseFile = rhs._databaseFile;
        this->_database = rhs._database;
    }
    return *this;
}

void BitcoinExchange::_loadDatabase(void){
    std::ifstream in;
    std::string tmp, date, rate;

    in.open(this->_databaseFile.c_str());
    if (in.fail())
        throw std::runtime_error("Failed to open file: 'data.csv'\n");
    std::getline(in, tmp);
    if (tmp != "date,exchange_rate")
        throw std::runtime_error("Wrong header on database file\n");
    while(std::getline(in, tmp)){
        int pos = tmp.find(',');
        date = tmp.substr(0, pos);
        rate = tmp.substr(pos + 1);
        _database[date] = atof(rate.c_str());
    }

}

void BitcoinExchange::_loadInputFile(void){
    std::ifstream in;
    std::string tmp, date, rate;

    in.open(this->_inputFile.c_str());
    if (in.fail())
        throw std::runtime_error("Failed to open the input file\n");
    std::getline(in, tmp);
    if (tmp != "date | value")
        throw std::runtime_error("Wrong header on input file\n");
    while(std::getline(in, tmp)){
        if (tmp.find('|') == std::string::npos || tmp.empty())
            std::cout <<"Error: bad input => "<<tmp<<"\n";
        int pos = tmp.find('|');
        date = tmp.substr(0, pos);
        rate = tmp.substr(pos + 1);
    }
}
 
bool BitcoinExchange::_validateYear(int year, int month, int day){
    if (year < 2009 || year > 2023)
        return false;
    if (year == 2009 &&(month != 01 || day != 01))
        return false;
    return true;
}

bool BitcoinExchange::_validateDay(int day, int month, int year){
    int lastDay = 31;

    if (month == 4 || month == 6 || 
            month == 9 || month == 11)
        lastDay = 30;
    else if (month == 02)
        lastDay = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ?
            29 : 28;
    if (day > lastDay)
        return false;
    return true;
}

bool BitcoinExchange::_validateMonth(int month){
    if (month < 1 || month > 12)
        return false;
    return true;
}

