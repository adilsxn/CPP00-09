#include "../inc/Serializer.hpp"

Serializer::Serializer(void){
    return ;
}

Serializer::Serializer(const Serializer & src){
    (void)src;
}

Serializer &Serializer::operator=(const Serializer & rhs){
    (void)rhs;
    return *this;
}

Serializer::~Serializer(void){
    return ;
}

uintptr_t Serializer::serialize(Data *ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw){
    return reinterpret_cast<Data* >(raw);
}
