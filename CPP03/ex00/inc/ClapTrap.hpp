#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
class ClapTrap{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ~ClapTrap(void);
        ClapTrap(ClapTrap const& src);
        ClapTrap& operator=(ClapTrap const& rhs);
        void  setName(std::string name);
        std::string getName(void)const;
        int getHitPoints(void)const;
        int getEnergyPoints(void)const;
        int  getAttackDamage(void)const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif
