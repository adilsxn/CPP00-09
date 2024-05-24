#include "../inc/ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(void):
    _name("Robot"), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
    std::cout << "Default Constructor called\n";
    return ;
}


ClapTrap::ClapTrap(std::string name):
    _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30)
{
    std::cout << "Constructor for "<<name<<" called\n";
    return ;
}


ClapTrap::~ClapTrap(void){
    std::cout << "Destructor for "<<this->_name<<" called\n";
    return ;
}

ClapTrap::ClapTrap(ClapTrap const& src){
    std::cout << "Copy Constructor called\n";
    *this = src;
    return;
}

void ClapTrap::setName(std::string name){
    this->_name = name;
}

std::string ClapTrap::getName(void)const{
    return this->_name;
}


int ClapTrap::getHitPoints(void)const{
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void)const{
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void)const{
    return this->_attackDamage;
}



ClapTrap& ClapTrap::operator=(ClapTrap const& rhs){
    std::cout << "Copy assignment operator\n";
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_energyPoints= rhs.getEnergyPoints();
        this->_hitPoints = rhs.getHitPoints();
        this->_attackDamage= rhs.getAttackDamage();
    }
    return *this;
}

void ClapTrap::attack(const std::string& target){

    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout<<"ClapTrap "<<this->getName()<< " attacks "<<target;
        std::cout<<", causing "<< this->_attackDamage <<" points of damage\n";
        this->_energyPoints--;
    }
    else
    {
        std::cout<<"ClapTrap "<<this->getName()<< " tries to repair:\n";
        if (this->_hitPoints <= 0)
            std::cout<<"\thas 0 hit points left\n";
        if (this->_hitPoints <= 0)
            std::cout<< "\thas 0 energy points left\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (amount > 0 ){
        if (this->_hitPoints != 0)
            this->_hitPoints -=(int)amount;
        std::cout <<"ClapTrap "<<this->getName()<<" has taken "<<amount;
        std::cout <<" hit points, Total hit points now: " <<this->_hitPoints;
        std::cout <<"\n\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_energyPoints > 0 && this->_hitPoints > 0 && amount > 0){
        this->_hitPoints += (int)amount;
        std::cout<<"ClapTrap "<<this->getName()<<" has been repaired ";
        std::cout<<amount<<" hit points, Total hit points now: ";
        std::cout<<this->_hitPoints<<"\n";
        this->_energyPoints--;
    }
    else
    {

        if (this->_hitPoints <= 0)
            std::cout<<"ClapTrap "<<this->getName()<<" has 0 hit points left\n";
        if (this->_hitPoints <= 0)
            std::cout<<"ClapTrap "<<this->getName()<<" has 0 energy points left\n";
    }
}


