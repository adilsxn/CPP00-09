#include "../inc/DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(void):ClapTrap(), ScavTrap(), FragTrap(){
    std::cout << "Default Constructor for DiamondTrap called\n";
    this->_name = "Robot";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    return ;
}

DiamondTrap::DiamondTrap(std::string name):
    ClapTrap(name + "_clap_name"),
    ScavTrap(name + "_scav_Name"), 
    FragTrap(name + "_frag_Name")
{
    std::cout << "Constructor for DiamondTrap "<<name<<" called\n";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    return ;
}


DiamondTrap::~DiamondTrap(void){
    std::cout << "Destructor for DiamondTrap "<<this->_name<<" called\n";
    return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src):
    ClapTrap(src),
    ScavTrap(src),
    FragTrap(src)
{
    std::cout << "Copy Constructor for DiamondTrap called\n";
    *this = src;
    return;
}

void DiamondTrap::setName(std::string name){
    this->_name = name;
}

std::string DiamondTrap::getName(void)const{
    return this->_name;
}


DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs){
    std::cout << "Copy assignment operator\n";
    if (this != &rhs)
    {
        this->_name = getName();
        this->_hitPoints = FragTrap::_hitPoints;
        this->_energyPoints = ScavTrap::_energyPoints;
        this->_attackDamage = FragTrap::_attackDamage;
    }
    return *this;
}

void DiamondTrap::whoAmi(){
    std::cout << "I am " <<this->getName();
    std::cout <<" descendant of "<<ClapTrap::_name<<"\n";
}
