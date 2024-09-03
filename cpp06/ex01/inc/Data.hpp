#pragma once

#include <iostream>
#include <string>

class Data {
private:
    std::string firstName;
    std::string lastName;
    int age;

public:
    Data();
    Data(const std::string &firstName, const std::string &lastName, int age);
    ~Data();
    Data(const Data &other);
    Data &operator=(const Data &other);

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    int getAge() const;
};

std::ostream &operator<<(std::ostream &os, const Data &data);
