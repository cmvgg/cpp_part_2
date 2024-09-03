#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::createTreeFile() const {
    std::ofstream file((_target + "_shrubbery").c_str());
    if (file) {
        file << "ASCII ART OF A TREE\n";
    } else {
        std::cerr << "Failed to open file for writing.\n";
    }
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
    if (!isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (bureaucrat.getGrade() > getExecuteGrade()) {
        throw AForm::GradeTooLowException();
    }
    createTreeFile();
}
