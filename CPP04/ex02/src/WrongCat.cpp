#include <iostream>
#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void):WrongAnimal(),_type("WrongCat"){
    std::cout << "WrongCat constructed\n";
}

WrongCat::WrongCat(WrongCat const& src):WrongAnimal(src){
    std::cout << "WrongCat copy constructed\n";
    *this = src;
    return ;
}

std::string WrongCat::getType()const{
    return this->_type;
}

void WrongCat::setType(std::string type){
    this->_type = type;
    return ;
}

void WrongCat::makeSound()const{
    std::cout << "The "<<this->getType()<<" wrongmeows\n";
}

WrongCat& WrongCat::operator=(WrongCat const& rhs){
    std::cout << "WrongCat copy assigned\n";
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat of type "<<this->getType()<<" destroyed\n";
}
