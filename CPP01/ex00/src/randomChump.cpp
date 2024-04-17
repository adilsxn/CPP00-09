#include "../inc/Zombie.hpp"

void randomChump(std::string name)
{
    Zombie babyz = Zombie(name);
    babyz.announce();
};
