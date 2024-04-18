#include "../inc/Zombie.hpp"
#include <iostream>

Zombie::~Zombie(void){
    std::cout << this->_name + " vanishes\n";
    return ;
};

void Zombie::announce(void)
{
    std::cout << this->_name + ": " + "BraiiiiiiinnnzzzZ...\n";
    return ;
}

Zombie::Zombie(void){
    std::cout <<"Zombie appears";
    return ;
};

