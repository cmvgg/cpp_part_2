#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream>

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cerr << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    A* a = dynamic_cast<A*>(&p);
    if (a) {
        std::cout << "A" << std::endl;
        return;
    }
    
    B* b = dynamic_cast<B*>(&p);
    if (b) {
        std::cout << "B" << std::endl;
        return;
    }
    
    C* c = dynamic_cast<C*>(&p);
    if (c) {
        std::cout << "C" << std::endl;
        return;
    }
    
    std::cerr << "Unknown type" << std::endl;
}
