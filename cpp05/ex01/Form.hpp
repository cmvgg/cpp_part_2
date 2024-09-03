#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeRequiredToSign;
    const int gradeRequiredToExecute;

public:
    Form(void);
    ~Form(void);
    Form(const Form &other);
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form &operator=(const Form &other);
    
    const std::string &getName(void) const;
    bool getIsSigned(void) const;
    int getGradeRequiredToSign(void) const;
    int getGradeRequiredToExecute(void) const;
    void beSigned(const Bureaucrat &bureaucrat);

public:
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);
