#include "../inc/BitcoinExchange.hpp"
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <ctime>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <iomanip>

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

time_t BitcoinExchange::_getEpochFromStr(std::string& date){
    struct tm tm;
    bzero(&tm, sizeof tm);
    strptime(date.c_str(), "%Y-%m-%d", &tm);
    time_t epoch = mktime(&tm);
    return epoch;
}

std::string BitcoinExchange::_getStrFromEpoch(time_t date){
    struct tm *toStr = localtime(&date);

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << toStr->tm_year + 1900;
    ss << "-" << std::setfill('0') << std::setw(2) << toStr->tm_mon + 1;
    ss << "-" << std::setfill('0') << std::setw(2) << toStr->tm_mday;

    return ss.str();
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
        time_t epoch = _getEpochFromStr(date);
        rate = tmp.substr(pos + 1);
        double rateValue = atof(rate.c_str());
        this->_database[epoch] = rateValue;
    }

}


std::string trimSpace(std::string input)
{
    const char* s = " \t\n\r\f\v";
    int end  =  input.find_last_not_of(s);
    int start =  input.find_first_not_of(s);
    if (start == end)
        return input;
    return input.substr(start, end - start + 1);
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
        std::cout <<"\nInput: "<<tmp<<"\n";
        if (tmp.find('|') == std::string::npos || tmp.empty())
            std::cout <<"Error: bad input => "<<tmp<<"\n";
        else{
            int pos = tmp.find('|');
            date = trimSpace(tmp.substr(0, pos));
            rate = tmp.substr(pos + 1);
            double tmp_rate = atof(rate.c_str());
            try{
                _getBitcoinValue(date, tmp_rate);
            }
            catch(std::exception& e){
                std::cout <<e.what();
            }
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

void BitcoinExchange::_getRateValue(time_t epoch, double value){
    double rateValue = 0.0;
    std::map<time_t, double>::iterator it;
    it = _database.find(epoch);
    if (it != _database.end())
       rateValue = it->second;
    else{
        for (it = _database.begin(); it != _database.end(); it++){
            std::map<time_t, double>::iterator next = it;
            next++;
            if (((epoch >= it->first) && (next == _database.end()))
                 || ((epoch >= it->first) && (epoch < next->first)))
                    break;
        }
        rateValue = it->second;
    }
    std::cout<<std::fixed;
    std::cout.precision(2);
    std::cout<<"Closest exchange data: "
        <<_getStrFromEpoch(it->first)
        <<" -> "<<rateValue;
    std::cout<<"\n"
        <<"["<<_getStrFromEpoch(epoch)<<"]"<<" "
        <<rateValue<< " * "<<value<<" = "
         <<rateValue * value<<"\n";
    // std::cout <<"\n";
}

void BitcoinExchange::_getBitcoinValue(std::string& date, double value){
    if (!_validateDate(date))
    {
        std::string s("Error: bad input => " + date +"\n");
        throw std::runtime_error (s.c_str());
    }
    else if (value < 0)
        throw std::runtime_error("Error: not a positive number.\n");
    else if (value > 1000 )
       throw std::runtime_error("Error: too large a number.\n");
    time_t epoch = _getEpochFromStr(date);
    _getRateValue(epoch, value);
}

bool BitcoinExchange::_validateDate(std::string& date) const{
    char delimiter;
    std::stringstream ss(date);
    int day, month, year;
    if (date.length() < 8 || date.length() > 10)
        return false;
    if (!(ss >> year >> delimiter >> month >> delimiter >> day))
        return false;
    if (this->_validateYear(year, month, day) == false|| 
            this->_validateDay(day, month, year) == false||
            this->_validateMonth(month) == false)
        return false;
    return true;
}
bool BitcoinExchange::_validateYear(int year, int month, int day) const{
    if (year < 2009 || year > 2023)
        return false;
    if (year == 2009 &&(month == 01 && day == 01))
        return false;
    return true;
}

bool BitcoinExchange::_validateDay(int day, int month, int year) const{
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

bool BitcoinExchange::_validateMonth(int month) const{
    if (month < 1 || month > 12)
        return false;
    return true;
}

