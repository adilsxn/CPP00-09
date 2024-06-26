#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class AMateria;
class ICharacter{};

class Character: public ICharacter {
public:
    Character(void);
    Character(const Character &);
    Character &operator=(const Character &);
    ~Character(void);

private:
    static int const	_inventorySize = 4;
    std::string	_name;
    AMateria *	_inventory[_inventorySize];

    void	_initializeEmptyInventory(void);
    void	_deleteInventory(void);
    
};
#endif // !CHARACTER_HPP
