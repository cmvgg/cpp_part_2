#include "../inc/Data.hpp"

Data::Data(): firstName("John"), lastName("Doe"), age(30) {}

Data::Data(const std::string &firstName, const std::string &lastName, int age)
    : firstName(firstName), lastName(lastName), age(age) {}

Data::~Data() {}

Data::Data(const Data &other) {
    *this = other;
}

Data &Data::operator=(const Data &other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        age = other.age;
    }
    return *this;
}

const std::string &Data::getFirstName() const {
    return firstName;
}

const std::string &Data::getLastName() const {
    return lastName;
}

int Data::getAge() const {
    return age;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
    os << data.getFirstName() << " " << data.getLastName() << " " << data.getAge();
    return os;
}
