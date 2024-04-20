#include "../inc/Zombie.hpp"
#include <iostream>

Zombie::~Zombie(void){
    std::cout << this->_name + " vanishes\n";
    return ;
};

void Zombie::setName(std::string name)
{
    this->_name = name;
};

void Zombie::announce(void)
{
    std::cout << this->_name + ": " + "BraiiiiiiinnnzzzZ...\n";
    return ;
}

Zombie::Zombie(void){
    std::cout <<" A Zombie appears\n";
    return ;
};

