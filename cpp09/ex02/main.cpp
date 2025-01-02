#include "./PmergeMe.hpp"

int main(int ac, const char **av) {
    if (ac < 2) {
        std::cout << "Example use: -> ./PmergeMe 3 2 1" << std::endl;
        return (std::cerr << "Error: Invalid input" << std::endl, -42);
    }

    try {
        PmergeMe tmp(++av);
        tmp.print();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}
