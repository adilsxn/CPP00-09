#include "../inc/Data.hpp"
#include <iostream>

Data::Data(void){
    std::cout <<"Data created\n";
}

Data::Data(const Data & src){
    this->age = src.age;
    this->name = src.name;
    std::cout <<"Data copy constructed\n";
}

Data& Data::operator=(const Data & rhs){
    if (this != &rhs)
        *this = rhs;
    std::cout <<"Data copy assigned\n";
    return *this;
}

Data::~Data(void){
    std::cout <<"Data destroyed\n";
}




