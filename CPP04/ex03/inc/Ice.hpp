#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice {
public:
    Ice(void);
    Ice(const Ice & src);
    Ice &operator=(const Ice & rhs);
    ~Ice(void);
    AMateria* clone(void);
    void use(ICharacter& target);
};
#endif // !ICE_HPP
