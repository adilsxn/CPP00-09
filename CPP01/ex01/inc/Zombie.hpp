#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(void);
        ~Zombie(void);
        void setName(std::string name);
        void announce(void);
};

Zombie *zombieHord(int N, std::string name);
#endif
