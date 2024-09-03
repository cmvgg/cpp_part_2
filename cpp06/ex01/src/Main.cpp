#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"

int main(void) {
    std::string input[2];
    int age;

    std::cout << "name: -> ";
    std::cin >> input[0];

    std::cout << "lastName: -> ";
    std::cin >> input[1];

    std::cout << "age: -> ";
    std::cin >> age;

    if (std::cin.fail() || age < 0 || age > 120) {
        std::cerr << "Error: Age not valid. Please enter a number between 0 and 120." << std::endl;
        return 1;
    }

    Data originalData(input[0], input[1], age);
    Data copiedData(originalData);

    unsigned long rawAddress = Serializer::convertPointerToRaw(&copiedData);

    std::cout << "Serialized address: " << std::hex << rawAddress << std::dec << std::endl;

    Data *deserializedData = Serializer::convertRawToPointer(rawAddress);

    if (deserializedData == &copiedData) {
        std::cout << std::endl << "Data pointers are equal" << std::endl;
    } else {
        std::cout << "Data pointers are different" << std::endl;
    }

    std::cout << std::endl << "Data after deserialization: " << *deserializedData << std::endl;

    return 0;
}
