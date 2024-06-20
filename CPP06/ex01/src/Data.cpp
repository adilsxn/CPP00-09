#include "../inc/Data.hpp"
#include <iostream>

Data::Data(void):name(""), age(0){
    std::cout <<"Data created\n";
}

Data::Data(Data const& src){
    this->age = src.age;
    this->name = src.name;
    std::cout <<"Data copy constructed\n";
}

Data& Data::operator=(Data const& rhs){
    if (this != &rhs)
        *this = rhs;
    std::cout <<"Data copy assigned\n";
    return *this;
}

Data::~Data(void){
    std::cout <<"Data destroyed\n";
}




