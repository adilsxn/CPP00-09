#include <iostream>
#include "../inc/Cat.hpp"

Cat::Cat(void):_type("Cat"){
    std::cout << "Cat constructed\n";
}

Cat::Cat(Cat const& src):Animal(src){
    std::cout << "Cat copy constructed\n";
    *this = src;
    return ;
}

std::string Cat::getType()const{
    return this->_type;
}

void Cat::setType(std::string type){
    this->_type = type;
    return ;
}

void Cat::makeSound()const{
    std::cout << "The "<<this->getType()<<" meows\n";
}

Cat& Cat::operator=(Cat const& rhs){
    std::cout << "Cat copy assigned\n";
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat of type "<<this->getType()<<" destroyed\n";
}
