#include "../inc/HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon):_name(name), _weapon(weapon){
    std::cout << "HumanA " << name << " is created\n";
    std::cout << "\n";
    return ;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA " << _name << " is created\n";
    std::cout << "\n";
    return ;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << _weapon.getType() << "\n";
}
