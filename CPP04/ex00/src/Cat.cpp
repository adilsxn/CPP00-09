#include <iostream>
#include "../inc/Cat.hpp"

Cat::Cat(void):Animal(){
    std::cout << "Cat constructed\n";
    this->_type = "Cat";
}

Cat::Cat(Cat const& src):Animal(src){
    std::cout << "Cat copy constructed\n";
    *this = src;
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
