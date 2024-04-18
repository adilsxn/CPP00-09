#include "../inc/Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie john = Zombie("John");
    Zombie *paul = newZombie("Paul");

    std::cout << "Zombie on the stack\n";
    john.announce();

    std::cout << "Zombie on the heap\n";
    paul->announce();

    std::cout << "A random chump appears\n";
    randomChump("Chump");
    randomChump("Chomp");
    randomChump("Champ");
    
    delete paul;
    return 0;
}
