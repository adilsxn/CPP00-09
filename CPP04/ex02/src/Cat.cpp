#include <cstddef>
#include <iostream>
#include <string>
#include "../inc/Cat.hpp"

Cat::Cat(void):A_Animal(), _brain(new Brain ()){
    this->_type = "Cat";
    std::cout << "Cat constructed\n";
}

Cat::Cat(Cat const& src):A_Animal(src), _brain(NULL){
    std::cout << "Cat copy constructed\n";
    *this = src;
    return ;
}

std::string Cat::getType()const{
    return this->_type;
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
        if (this->_brain != NULL)
            delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
    }
    return *this;
}

Cat::~Cat(){
    delete this->_brain;
    std::cout << "Cat of type "<<this->getType()<<" destroyed\n";
}
