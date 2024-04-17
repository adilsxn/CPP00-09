#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        ~Zombie(void);
        Zombie(std::string name);
        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif
