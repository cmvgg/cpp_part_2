#pragma once

#include "Data.hpp"

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);

public:
    static unsigned long convertPointerToRaw(Data *ptr);
    static Data *convertRawToPointer(unsigned long raw);
};
