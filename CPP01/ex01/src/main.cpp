#include "../inc/Zombie.hpp"
#include <iostream>

int main (void)
{
    int n = 7;
    Zombie *rumble = zombieHord(n, "Bubushka");

    std::cout << "A zombie hord straight from the heap\n";
    std::cout << "\n";
    for(int i = 0; i < n; i++) 
    {
        std::cout << i << " ";
        rumble[i].announce();
        std::cout << "\n";
    }
    std::cout << "That was the rumble\n";
    delete[] rumble;
    return 0;
}
