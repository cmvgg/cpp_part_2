#include "../inc/ScalarConvert.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Argument count != 2" << std::endl;
        return 1;
    }
    
    try {
        ScalarConvert::convert(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
