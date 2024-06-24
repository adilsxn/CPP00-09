#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure {
public:
    Cure();
    Cure(const Cure & src);
    Cure &operator=(const Cure & rhs);
    ~Cure();
    AMateria* clone(void);
    void use(ICharacter& target);
};
#endif // !CURE_HPP
