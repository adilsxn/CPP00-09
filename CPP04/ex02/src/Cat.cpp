#include <iostream>
#include <string>
#include "../inc/Cat.hpp"

Cat::Cat(void):A_Animal(),_type("Cat"){
    this->_brain = new Brain();
    std::cout << "Cat constructed\n";
}

Cat::Cat(Cat const& src):A_Animal(src){
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

void Cat::teachCat(std::string const& rhs){
    this->_brain->learn(rhs);
    return ;
}

void Cat::hunnidMeows(void)const{
    this->_brain->speak();
}

void Cat::makeSound()const{
    std::cout << "The "<<this->getType()<<" meows\n";
}

Cat& Cat::operator=(Cat const& rhs){
    std::cout << "Cat copy assigned\n";
    if (this != &rhs)
    {
        this->_type = rhs.getType();
        this->_brain = new Brain();
    }
    return *this;
}

Cat::~Cat(){
    delete this->_brain;
    std::cout << "Cat of type "<<this->getType()<<" destroyed\n";
}
