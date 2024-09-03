#include "Form.hpp"

Form::~Form(void) {}

Form::Form(void) : name("default"), isSigned(false), gradeRequiredToSign(42), gradeRequiredToExecute(42) {}

Form::Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute)
{
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw GradeTooHighException();
    else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() >= gradeRequiredToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const std::string &Form::getName(void) const { return name; }
bool Form::getIsSigned(void) const { return isSigned; }
int Form::getGradeRequiredToSign(void) const { return gradeRequiredToSign; }
int Form::getGradeRequiredToExecute(void) const { return gradeRequiredToExecute; }

const char *Form::GradeTooHighException::what(void) const throw()
{
    return "Grade too high";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << form.getName() << ", Form grade required to sign " << form.getGradeRequiredToSign() << ", degree of execution " << form.getGradeRequiredToExecute() << ", signed: " << (form.getIsSigned() ? "Yes" : "No") << ".";
    return os;
}
