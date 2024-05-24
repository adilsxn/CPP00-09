#include "../inc/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void):ClapTrap()
{
    std::cout << "Default Constructor for FragTrap called\n";
    return ;
}


FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    std::cout << "Constructor for FragTrap "<<name<<" called\n";
    return ;
}


FragTrap::~FragTrap(void){
    std::cout << "Destructor for FragTrap "<<this->_name<<" called\n";
    return ;
}

FragTrap::FragTrap(FragTrap const& src):ClapTrap(src)
{
    std::cout << "Copy Constructor for FragTrap called\n";
    *this = src;
    return;
}


FragTrap& FragTrap::operator=(FragTrap const& rhs){
    std::cout << "Copy assignment operator for FragTrap\n";
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_energyPoints= rhs.getEnergyPoints();
        this->_hitPoints = rhs.getHitPoints();
        this->_attackDamage= rhs.getAttackDamage();
    }
    return *this;
}

void FragTrap::attack(const std::string& target){

    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout<<"FragTrap "<<this->getName()<< " attacks "<<target;
        std::cout<<", causing "<< this->_attackDamage <<" points of damage\n";
        this->_energyPoints--;
    }
    else
    {
        std::cout<<"FragTrap "<<this->getName()<< " tries to repair:\n";
        if (this->_hitPoints <= 0)
            std::cout<<"\thas 0 hit points left\n";
        if (this->_hitPoints <= 0)
            std::cout<< "\thas 0 energy points left\n";
    }
}

void FragTrap::highFiveGuys(){
    std::cout <<this->getName()<<" goes for the High Five\n";
}
