#include "../inc/ScalarConvert.hpp"
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

void ScalarConvert::convertFromChar(char c, int &d, float &f, double &dd) {
    d = static_cast<int>(c);
    f = static_cast<float>(c);
    dd = static_cast<double>(c);
}

void ScalarConvert::convertFromInt(const std::string &s, int &d, float &f, double &dd) {
    std::istringstream iss(s);
    iss >> d;
    if (iss.fail() || !iss.eof()) {
        throw std::runtime_error("Invalid integer value");
    }
    f = static_cast<float>(d);
    dd = static_cast<double>(d);
}

void ScalarConvert::convertFromFloat(const std::string &s, float &f, double &dd) {
    std::istringstream iss(s);
    iss >> f;
    if (iss.fail() || !iss.eof()) {
        throw std::runtime_error("Invalid float value");
    }
    dd = static_cast<double>(f);
}

void ScalarConvert::convertFromDouble(const std::string &s, double &dd) {
    std::istringstream iss(s);
    iss >> dd;
    if (iss.fail() || !iss.eof()) {
        throw std::runtime_error("Invalid double value");
    }
}

void ScalarConvert::printChar(char c) {
    if (std::isprint(c)) {
        std::cout << c;
    } else {
        std::cout << "Non displayable";
    }
}

void ScalarConvert::printInt(int d) {
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "impossible";
    } else {
        std::cout << d;
    }
}

void ScalarConvert::printFloat(float f) {
    if (std::isinf(f)) {
        std::cout << (f > 0 ? "+inf" : "-inf");
    } else if (std::isnan(f)) {
        std::cout << "nanf";
    } else {
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    }
}

void ScalarConvert::printDouble(double dd) {
    if (std::isinf(dd)) {
        std::cout << (dd > 0 ? "+inf" : "-inf");
    } else if (std::isnan(dd)) {
        std::cout << "nan";
    } else {
        std::cout << std::fixed << std::setprecision(1) << dd;
    }
}

void ScalarConvert::convert(const std::string &input) {
    int d = 0;
    float f = 0;
    double dd = 0;

    // Check for special values
    if (input == "nan" || input == "-nan" || input == "+nan") {
        dd = std::numeric_limits<double>::quiet_NaN();
        f = static_cast<float>(dd);
    } else if (input == "-inf" || input == "+inf" || input == "inf") {
        dd = std::numeric_limits<double>::infinity();
        f = std::numeric_limits<float>::infinity();
    } else if (input.length() == 1 && !std::isdigit(input[0])) {
        convertFromChar(input[0], d, f, dd);
    } else if (input.find('.') != std::string::npos || input.find('e') != std::string::npos) {
        if (input.find('f') != std::string::npos) {
            convertFromFloat(input, f, dd);
        } else {
            convertFromDouble(input, dd);
            f = static_cast<float>(dd); // Ensure float is also updated
        }
    } else {
        convertFromInt(input, d, f, dd);
    }

    // Print results
    std::cout << "char: ";
    printChar(static_cast<char>(d));
    std::cout << std::endl;

    std::cout << "int: ";
    if (std::isnan(dd) || std::isinf(dd) || dd > std::numeric_limits<int>::max() || dd < std::numeric_limits<int>::min()) {
        std::cout << "impossible";
    } else {
        printInt(d);
    }
    std::cout << std::endl;

    std::cout << "float: ";
    printFloat(f);
    std::cout << std::endl;

    std::cout << "double: ";
    printDouble(dd);
    std::cout << std::endl;
}
