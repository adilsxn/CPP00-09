#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class FragTrap: virtual public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap(FragTrap const& src);
        FragTrap& operator=(FragTrap const& rhs);
        void attack(const std::string& target);
        void highFiveGuys(void);
};
#endif
