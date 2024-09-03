#include "../inc/Serializer.hpp"

unsigned long Serializer::convertPointerToRaw(Data *ptr) {
    return reinterpret_cast<unsigned long>(ptr);
}

Data *Serializer::convertRawToPointer(unsigned long raw) {
    return reinterpret_cast<Data *>(raw);
}
