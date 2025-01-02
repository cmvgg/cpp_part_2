#include "../inc/ScalarConvert.hpp"

void ScalarConvert::convertFromChar(char c, int &d, float &f, double &dd) {
    d = static_cast<int>(c);
    f = static_cast<float>(c);
    dd = static_cast<double>(c);
}

void ScalarConvert::convertFromInt(const std::string &s, int &d, float &f, double &dd) {
    d = convertToInt(s);
    f = static_cast<float>(d);
    dd = static_cast<double>(d);
}

void ScalarConvert::convertFromFloat(const std::string &s, float &f, double &dd) {
    f = convertToFloat(s);
    dd = static_cast<double>(f);
}

void ScalarConvert::convertFromDouble(const std::string &s, double &dd) {
    dd = convertToDouble(s);
}

int ScalarConvert::convertToInt(const std::string &s) {
    int result;
    std::stringstream ss(s);
    ss >> result;
    if (ss.fail() || !ss.eof()) {
        throw std::runtime_error("Invalid integer value");
    }
    return result;
}

float ScalarConvert::convertToFloat(const std::string &s) {
    float result;
    std::stringstream ss(s);
    ss >> result;
    if (ss.fail() || !ss.eof()) {
        throw std::runtime_error("Invalid float value");
    }
    return result;
}

double ScalarConvert::convertToDouble(const std::string &s) {
    double result;
    std::stringstream ss(s);
    ss >> result;
    if (ss.fail() || !ss.eof()) {
        throw std::runtime_error("Invalid double value");
    }
    return result;
}

void ScalarConvert::printChar(char c) {
    if (std::isprint(c)) {
        std::cout << c;
    } else {
        std::cout << "Non displayable";
    }
}

void ScalarConvert::printInt(int d) {
    if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min()) {
        std::cout << d;
    } else {
        std::cout << "impossible";
    }
}

void ScalarConvert::printFloat(float f) {
    std::cout << std::fixed << std::setprecision(1) << f << "f";
}

void ScalarConvert::printDouble(double dd) {
    std::cout << std::fixed << std::setprecision(1) << dd;
}

void ScalarConvert::convert(const std::string &input) {
    int d = 0;
    float f = 0;
    double dd = 0;
    
    if (input.length() == 1 && !std::isdigit(input[0])) {
        convertFromChar(input[0], d, f, dd);
    } else if (input.find('.') != std::string::npos) {
        if (input.find('f') != std::string::npos) {
            convertFromFloat(input, f, dd);
        } else {
            convertFromDouble(input, dd);
        }
    } else {
        convertFromInt(input, d, f, dd);
    }
    
    std::cout << "char: ";
    printChar(static_cast<char>(d));
    std::cout << std::endl;
    
    std::cout << "int: ";
    printInt(d);
    std::cout << std::endl;
    
    std::cout << "float: ";
    printFloat(f);
    std::cout << std::endl;
    
    std::cout << "double: ";
    printDouble(dd);
    std::cout << std::endl;
}
