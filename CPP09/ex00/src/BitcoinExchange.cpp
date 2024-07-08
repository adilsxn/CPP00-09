#include "../inc/BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>

BitcoinExchange::BitcoinExchange(void):_databaseFile("data.csv"){
    this->_loadDatabase();
    return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src){
    *this = src;
    return ;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs){
    if (this != &rhs){
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
        float rateValue = atof(rate.c_str());
        // if(_validateDate(date) == false 
        //         || (rateValue < 0 || rateValue > 1000))
        // {
        //     std::cout <<date<<" | "<<rate<<"\n";
        //     throw std::runtime_error("Error: corrupted database\n");
        // }
        this->_database[date] = rateValue;
    }

}

void BitcoinExchange::_loadInputFile(std::string& inputFile){
    std::ifstream in;
    std::string tmp, date, rate;

    in.open(inputFile.c_str());
    if (in.fail())
        throw std::runtime_error("Failed to open the input file\n");
    std::getline(in, tmp);
    if (tmp != "date | value")
        throw std::runtime_error("Wrong header on input file\n");
    while(std::getline(in, tmp)){
        if (tmp.find('|') == std::string::npos || tmp.empty())
        {
            std::cout <<"Error: bad input => "<<tmp<<"\n";
            continue ;
        }
        int pos = tmp.find('|');
        date = tmp.substr(0, pos);
        rate = tmp.substr(pos + 1);
        float tmp_rate = atof(rate.c_str());
        try{
            _getBitcoinValue(date, tmp_rate);
        }
        catch(std::exception& e){
            std::cout <<e.what();
        }
    }
}

void BitcoinExchange::startExchange(const char *inputFile){
    std::string ss (inputFile);
    this->_loadInputFile(ss);
    return ;
}

BitcoinExchange::~BitcoinExchange(void){
    return ;
}

void BitcoinExchange::_getBitcoinValue(std::string date, float value) {
    float rateValue;
    if (!this->_validateDate(date))
    {
        std::string s("Error: bad input => " + date +"\n");
        throw std::runtime_error (s.c_str());
    }
    else if (value < 0)
        throw std::runtime_error("Error: not a positive number.\n");
    else if (value > 1000 )
       throw std::runtime_error("Error: too large a number.\n");
    else if(this->_database.count(date) == 1)
       rateValue = this->_database[date];
    else
        rateValue = this->_database.upper_bound(date)->second;;
    std::cout <<date<<" => "<<value<<" = "
        <<rateValue * value<<"\n";
}

bool BitcoinExchange::_validateDate(std::string& date){
    char delimiter;
    int day, month, year;
    std::stringstream ss(date);
    ss >> year >> delimiter >> month >> delimiter >> day;
    if (this->_validateYear(year, month, day) == false|| 
            this->_validateDay(day, month, year) == false||
            this->_validateMonth(month) == false)
        return false;
    return true;
}
bool BitcoinExchange::_validateYear(int year, int month, int day){
    if (year < 2009 || year > 2023)
        return false;
    if (year == 2009 &&(month == 01 && day == 01))
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

