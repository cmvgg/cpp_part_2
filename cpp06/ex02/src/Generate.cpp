#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int random = std::rand() % 3;

    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}
