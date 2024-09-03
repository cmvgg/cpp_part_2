#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream>

int main() {
    Base* p = generate();

    if (p) {
        std::cout << "Using pointer:" << std::endl;
        identify(p);

        std::cout << "Using reference:" << std::endl;
        identify(*p);

        delete p;
    } else {
        std::cerr << "Failed to generate object" << std::endl;
    }

    return 0;
}