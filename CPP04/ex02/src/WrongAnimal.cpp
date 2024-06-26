#include <iostream>
#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):_type("Blank"){
    std::cout << "WrongAnimal constructed\n";
}


WrongAnimal::WrongAnimal(WrongAnimal const& src){
    std::cout << "WrongAnimal copy constructed\n";
    *this = src;
    return ;
}

std::string WrongAnimal::getType()const{
    return this->_type;
}

void WrongAnimal::makeSound()const{
    std::cout << "The "<<this->getType()<<" wronganimals\n";
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs){
    std::cout << "WrongAnimal copy assigned\n";
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal of type "<<this->getType()<<" destroyed\n";
}






