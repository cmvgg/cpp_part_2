#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 32);
        Form test("Test Form", 30, 40);

        john.signForm(test);

        std::cout << test << std::endl;
        std::cout << john << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
