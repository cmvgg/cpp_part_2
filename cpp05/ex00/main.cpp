#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat tmp2("john", 100);
        std::cout << "[>>Start<<]\n" << tmp2 << std::endl;
        tmp2.decrement();
        std::cout << tmp2 << std::endl;

        Bureaucrat *bureaucrats = new Bureaucrat[10];

        for (int i = 0; i < 10; ++i)
        {
            bureaucrats[i].increment();
            std::cout << bureaucrats[i] << std::endl;
            bureaucrats[i].decrement();
            for (int t = 0; t < 10; ++t)
                bureaucrats[i].increment();
            std::cout << bureaucrats[i] << std::endl;
            std::cout << std::endl;
        }

        tmp2.decrement();
        std::cout << tmp2 << std::endl;

        tmp2.increment();
        std::cout << tmp2 << std::endl;

        tmp2.decrement();
        std::cout << tmp2 << std::endl;

        tmp2.increment();
        std::cout << tmp2 << std::endl;

        Bureaucrat tmp(tmp2);
        std::cout << tmp << std::endl;

        delete[] bureaucrats;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
