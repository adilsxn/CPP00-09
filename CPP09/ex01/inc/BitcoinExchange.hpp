#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(void);
    BitcoinExchange(std::string& inputFile);
    BitcoinExchange(const BitcoinExchange & src);
    BitcoinExchange &operator=(const BitcoinExchange & rhs);
    ~BitcoinExchange(void);
private:    
    std::map<std::string, float>_database;
    std::string _inputFile;
    std::string _databaseFile;
    bool _checkFile(void);
    void _loadDatabase(void);
    void _loadInputFile(void);
    void _getBitcoinValue(std::string date, float value);
    bool _validateDate(std::string& date);
    bool _validateDay(int date, int month, int year);
    bool _validateMonth(int month);
    bool _validateYear(int year, int month, int day);
    bool _validateRate(float value);
};

#endif // !BITCOINEXCHANGE_HPP
