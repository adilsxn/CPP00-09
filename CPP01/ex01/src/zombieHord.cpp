#include "../inc/Zombie.hpp"

Zombie *zombieHord(int N, std::string name)
{
    Zombie *babyz = new Zombie[N];

    for(int i = 0; i < N; i++)
        babyz[i].setName(name);
    return (babyz);
}
