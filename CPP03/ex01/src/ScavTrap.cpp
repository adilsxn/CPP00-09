#include <iostream>
#include "../inc/ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(){
    this->_name = "Robot";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_energyPoints = 20;
    std::cout<<"Default Constructor for ScavTrap called\n";
    return ;
}

ScavTrap::ScavTrap(ScavTrap const& src): ClapTrap(src){

    std::cout<<"Copy Constructor for ScavTrap called\n";
    *this = src;
    return ;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs){
    std::cout<<"Copy Assignment Operator for ScavTrap called\n";
    if (this != &rhs)
    {

        this->_name = rhs.getName();
        this->_energyPoints= rhs.getEnergyPoints();
        this->_hitPoints = rhs.getHitPoints();
        this->_attackDamage= rhs.getAttackDamage();
    }
    return *this;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_energyPoints = 20;
    std::cout<<"Parametrized Constructor for ScavTrap "<<name <<" called\n";
    return ; 
}

ScavTrap::~ScavTrap(void){
    std::cout<<"Default Destructor for ScavTrap "<<this->getName();
    std::cout<<" called\n";
    return ;
}


void ScavTrap::attack(const std::string& target){

    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout<<"ScavTrap "<<this->getName()<< " attacks "<<target;
        std::cout<<", causing "<< this->_attackDamage <<" points of damage\n";
        this->_energyPoints--;
    }
    else
    {
        std::cout<<"ScavTrap "<<this->getName()<< " tries to repair:\n";
        if (this->_hitPoints <= 0)
            std::cout<<"\thas 0 hit points left\n";
        if (this->_hitPoints <= 0)
            std::cout<< "\thas 0 energy points left\n";
    }
}


void ScavTrap::guardGate(void){
    std::cout <<"ScavTrap "<<getName();
    std::cout<<" is now in Gate keeper mode\n";
    return ;
}


