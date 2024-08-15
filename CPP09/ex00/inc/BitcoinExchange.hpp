#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <ctime>

class BitcoinExchange {
public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange & src);
    BitcoinExchange &operator=(const BitcoinExchange & rhs);
    void startExchange(const char *inputFile);
    ~BitcoinExchange(void);
private:    
    std::map<time_t, double>_database;
    std::string _databaseFile;
    bool _checkFile(void);
    void _loadDatabase(void);
    time_t _getEpochFromStr(std::string& date);
    std::string _getStrFromEpoch(time_t date);
    void _loadInputFile(std::string& inputFile);
    void _getBitcoinValue(std::string& date, double value);
    void _getRateValue(time_t epoch, double value);
    bool _validateDate(std::string& date)const;
    bool _validateDay(int date, int month, int year)const;
    bool _validateMonth(int month)const;
    bool _validateYear(int year, int month, int day)const;
    bool _validateRate(double value)const;
};

#endif // !BITCOINEXCHANGE_HPP
