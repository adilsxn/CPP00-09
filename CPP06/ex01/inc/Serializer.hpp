#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer {
public:
    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
    ~Serializer(void);
private:
    Serializer(void);
    Serializer(const Serializer & src);
    Serializer &operator=(const Serializer & rhs);
};
#endif // !SERIALIZER_HPP
