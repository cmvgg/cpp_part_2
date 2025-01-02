#include "./BitcoinExchange.hpp"
#include <boost/date_time/gregorian/gregorian.hpp>

bool isValidDate(const std::string& date) {
    try {
        boost::gregorian::date parsed_date(boost::gregorian::from_simple_string(date));
        return true;
    } catch (const boost::bad_lexical_cast&) {
        std::cerr << "Error: bad input >= " << date << std::endl;
        return false;
    }
}

BitcoinExchange::BitcoinExchange(void) {
    std::ifstream fileDb("data.csv");
    std::string line;

    if (!fileDb.is_open() || (getline(fileDb, line) && line.compare("date,exchange_rate")))
        throw std::runtime_error("error data base");

    getDb(fileDb, line);
    fileDb.close();
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (&other == this)
        return (*this);

    db = other.db;
    return (*this);
}

size_t BitcoinExchange::getDate(const std::string &line) const {
    std::istringstream ss(line);
    std::ostringstream tmp;
    size_t year, month, day;
    char dash[2];

    ss >> year >> dash[0] >> month >> dash[1] >> day;

    tmp << std::setw(4) << std::setfill('0') << static_cast<size_t>(year)
        << std::setw(2) << std::setfill('0') << static_cast<size_t>(month)
        << std::setw(2) << std::setfill('0') << static_cast<size_t>(day);

    return (static_cast<size_t>(atoi(tmp.str().data())));
}

void BitcoinExchange::getDb(std::ifstream &fileDb, std::string &line) {
    size_t date;
    float value;
    int i;

    while (getline(fileDb, line)) {
        i = line.find_first_of(',');
        date = getDate(line.substr(0, i));
        value = static_cast<float>(atof(line.substr(++i).data()));
        db.insert(std::pair<size_t, float>(date, value));
    }
}

void BitcoinExchange::open(const std::string &fileName) {
    std::ifstream file(fileName.data());
    if (!file) {
        std::cerr << "Error: could not open the file '" << fileName << "'" << std::endl;
        throw std::runtime_error("Error: file could not be opened");
    }

    std::string line, date, value;
    std::string::size_type i;

    if (!std::getline(file, line) || !line.compare("date | value") != 0) {
        std::cerr << "example file: \n\ndate | value" << std::endl;
        std::cerr << "2011-01-03 | 3\n" << std::endl;
        throw std::runtime_error("Error: invalid file format.");
    }

    while (std::getline(file, line)) {
        i = line.find_first_of("|");
        if (i == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, i);
        value = line.substr(i + 1);

        if (checkData(date, value))
            continue;

        size_t tmp = getDate(date);
        std::map<size_t, float>::iterator it = db.lower_bound(tmp);
        if (it != db.end() && it->first == tmp) {
            std::cout << date << " => " << value << " = " << (it->second * atof(value.c_str())) << std::endl;
        } else if (it != db.begin()) {
            --it;
            std::cout << date << " >= " << value << " = " << (it->second * atof(value.data())) << std::endl;
        } else {
            std::cout << date << " => " << value << " = " << (db.begin()->second * atof(value.c_str())) << std::endl;
        }
    }

    file.close();
}



bool BitcoinExchange::checkData(const std::string &date, const std::string &mount) const {
    int tmp = static_cast<int>(atof(mount.data()));

    if (checkDate(date))
        return (true);
    else if (tmp < 0)
        return (std::cerr << "Error: not a positive number." << std::endl, true);
    else if (tmp > 1000)
        return (std::cerr << "Error: too large a number." << std::endl, true);
    return (false);
}

bool BitcoinExchange::checkDate(const std::string &date) const {
    return !isValidDate(date);
}
