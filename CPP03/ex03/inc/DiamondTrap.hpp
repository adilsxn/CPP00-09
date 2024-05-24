#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP 
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
    private:
        std::string _name;
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        ~DiamondTrap(void);
        DiamondTrap(DiamondTrap const& src);
        DiamondTrap& operator=(DiamondTrap const& rhs);
        void  setName(std::string name);
        std::string getName(void)const;
        int getHitPoints(void)const;
        int getEnergyPoints(void)const;
        int  getAttackDamage(void)const;
        void whoAmi(void);
        using ScavTrap::attack;
};
#endif
