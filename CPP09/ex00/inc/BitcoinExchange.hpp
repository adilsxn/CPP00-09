#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange & src);
    BitcoinExchange &operator=(const BitcoinExchange & rhs);
    void startExchange(const char *inputFile);
    ~BitcoinExchange(void);
private:    
    std::map<std::string, double>_database;
    std::string _databaseFile;
    bool _checkFile(void);
    void _loadDatabase(void);
    void _loadInputFile(std::string& inputFile);
    void _getBitcoinValue(std::string date, float value);
    bool _validateDate(std::string& date);
    bool _validateDay(int date, int month, int year);
    bool _validateMonth(int month);
    bool _validateYear(int year, int month, int day);
    bool _validateRate(float value);
};

#endif // !BITCOINEXCHANGE_HPP
