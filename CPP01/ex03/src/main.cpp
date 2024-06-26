#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"


int main(void)
{
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    {
        Weapon *club = new Weapon("crude spiked club");

        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club->setType("some other type of club");
        jim.attack();
        delete club;
    }
    return 0;
    
}
