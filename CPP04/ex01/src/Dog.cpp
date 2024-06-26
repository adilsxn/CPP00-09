#include <iostream>
#include "../inc/Dog.hpp"


Dog::Dog(void):Animal(), _brain(new Brain()){
    this->_type = "Dog";
    std::cout << "Dog constructed\n";
}


Dog::Dog(Dog const& src): Animal(src), _brain(NULL){
    std::cout << "Dog copy constructed\n";
    *this = src;
    return ;
}

std::string Dog::getType()const{
    return this->_type;
}


void Dog::teachDog(std::string const& rhs){
    this->_brain->learn(rhs);
    return ;
}

void Dog::hunnidBarks(void)const{
    this->_brain->speak();
}

void Dog::makeSound()const{
    std::cout << "The "<<this->getType()<<" barks\n";
}

Dog& Dog::operator=(Dog const& rhs){
    std::cout << "Dog copy assigned\n";
    if (this != &rhs)
    {
        this->_type = rhs.getType();
        if (this->_brain != NULL)
            delete this->_brain;
        this->_brain = new Brain(*rhs._brain);
    }
    return *this;
}

Dog::~Dog(){
    delete this->_brain;
    std::cout << "Dog of type "<<this->getType()<<" destroyed\n";
}
