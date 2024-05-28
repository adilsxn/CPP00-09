#include <iostream>
#include "../inc/Dog.hpp"


Dog::Dog(void):Animal(),_type("Dog"){
    std::cout << "Dog constructed\n";
}


Dog::Dog(Dog const& src): Animal(src){
    std::cout << "Dog copy constructed\n";
    *this = src;
    return ;
}

std::string Dog::getType()const{
    return this->_type;
}

void Dog::setType(std::string type){
    this->_type = type;
    return ;
}

void Dog::makeSound()const{
    std::cout << "The "<<this->getType()<<" barks\n";
}

Dog& Dog::operator=(Dog const& rhs){
    std::cout << "Dog copy assigned\n";
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog of type "<<this->getType()<<" destroyed\n";
}
