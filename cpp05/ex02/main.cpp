#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat p("P", 1);

        ShrubberyCreationForm shrubForm("Garden");
        p.signForm(shrubForm);
        p.executeForm(shrubForm);

        RobotomyRequestForm robotForm("Robot");
        p.signForm(robotForm);
        p.executeForm(robotForm);

        PresidentialPardonForm presForm("Target");
        p.signForm(presForm);
        p.executeForm(presForm);

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
