#include "./BitcoinExchange.hpp"

int main(int ac, const char **av) {
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return (-42);
    }
    try {
        BitcoinExchange tmp;
        tmp.open(av[1]);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
