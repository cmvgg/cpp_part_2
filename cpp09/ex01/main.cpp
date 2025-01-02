#include "./RPN.hpp"

int main(int ac, const char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return -42;
    }

    try
    {
        RPN rpn;

        std::string input;
        for (int i = 1; i < ac; ++i)
        {
            input += av[i];
            if (i != ac - 1)
                input += ' ';
        }

        rpn.open(input);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
