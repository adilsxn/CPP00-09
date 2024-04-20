#include "../inc/Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie john = Zombie("John");
    Zombie *paul = newZombie("Paul");
    std::cout <<"\n";
    std::cout << "Zombie on the stack\n";
    john.announce();
    std::cout <<"\n";
    std::cout << "Zombie on the heap\n";
    paul->announce();
    std::cout <<"\n";
    std::cout << "The random chumps are appearing\n";
    randomChump("Chump"); 
    std::cout <<"\n";
    randomChump("Chomp");
    std::cout <<"\n";
    randomChump("Champ");
    std::cout <<"\n";
    delete paul;
    return 0;
}
