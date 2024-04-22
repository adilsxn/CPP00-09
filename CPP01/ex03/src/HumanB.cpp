#include "../inc/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name):_name(name), _weapon(NULL){
    std::cout << "HumanB " << name << " is created\n";
    std::cout << "\n";
    return ;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << _name << " is destroyed\n";
    std::cout << "\n";
    return ;
}

void HumanB::setWeapon(Weapon *weapon)
{
    _weapon = weapon;
};

void HumanB::attack(void)
{
    std::string tmp = _weapon->getType();
    std::cout << this->_name << " attacks with their " << tmp << "\n";
}
