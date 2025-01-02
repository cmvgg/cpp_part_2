#include <iostream>
#include <fstream>
#include <map>
#include <climits>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <boost/date_time/gregorian/gregorian.hpp>

class BitcoinExchange {
private:
    std::map<size_t, float> db;

private:
    void        getDb(std::ifstream &fileDb, std::string &line);
    bool        checkData(const std::string &date, const std::string &mount) const;
    bool        checkDate(const std::string &date) const;
    size_t      getDate(const std::string &line) const;

public:
    BitcoinExchange(void);
    ~BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    void open(const std::string &file);
};
