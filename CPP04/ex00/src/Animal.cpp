#include <iostream>
#include "../inc/Animal.hpp"

Animal::Animal(void):_type("Unknown animal"){
    std::cout << "Animal constructed\n";
}


Animal::Animal(Animal const& src){
    std::cout << "Animal copy constructed\n";
    *this = src;
    return ;
}

std::string Animal::getType()const{
    return this->_type;
}

void Animal::makeSound()const{
    std::cout << "The "<<this->getType()<<" animals\n";
}

Animal& Animal::operator=(Animal const& rhs){
    std::cout << "Animal copy assigned\n";
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal of type "<<this->getType()<<" destroyed\n";
}






