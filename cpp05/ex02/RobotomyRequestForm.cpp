#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (bureaucrat.getGrade() > getExecuteGrade()) {
        throw AForm::GradeTooLowException();
    }
    std::srand(std::time(0));
    std::cout << "Drilling noises...\n";
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully.\n";
    } else {
        std::cout << "Robotomy failed on " << _target << ".\n";
    }
}
