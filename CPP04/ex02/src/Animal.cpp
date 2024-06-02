#include <iostream>
#include "../inc/Animal.hpp"

A_Animal::A_Animal(void):_type("Blank"){
    std::cout << "Animal constructed\n";
}

A_Animal::A_Animal(A_Animal const& src){
    std::cout << "Animal copy constructed\n";
    *this = src;
    return ;
}

void A_Animal::setType(std::string type){
    this->_type = type;
    return ;
}



A_Animal& A_Animal::operator=(A_Animal const& rhs){
    std::cout << "Animal copy assigned\n";
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}

A_Animal::~A_Animal(){
    std::cout << "Animal destroyed\n";
}






