#include "../inc/Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type): _type(type)
{
    std::cout << "Weapon " << type << " is created\n";
    std::cout << "\n";
    return ;
};

Weapon::~Weapon(void)
{
    
    std::cout << "Weapon " << _type << " is destroyed\n";
    std::cout << "\n";
    return ;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

const std::string& Weapon::getType(void)
{
    return this->_type;
}

