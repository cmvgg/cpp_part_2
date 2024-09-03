#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>
#include <sstream>

class ScalarConvert {
private:
    static void printChar(char c);
    static void printInt(int d);
    static void printFloat(float f);
    static void printDouble(double dd);
    static void convertFromChar(char c, int &d, float &f, double &dd);
    static void convertFromInt(const std::string &s, int &d, float &f, double &dd);
    static void convertFromFloat(const std::string &s, float &f, double &dd);
    static void convertFromDouble(const std::string &s, double &dd);
    static int convertToInt(const std::string &s);
    static float convertToFloat(const std::string &s);
    static double convertToDouble(const std::string &s);
    
public:
    static void convert(const std::string &input);
};
