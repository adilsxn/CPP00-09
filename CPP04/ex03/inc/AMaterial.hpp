#ifndef AMATERIAL_HPP
#define AMATERIAL_HPP
#include "ICharacter.hpp"
#include <string>
class AMateria {
    protected:

    public:
        AMateria(void);
        virtual ~AMateria(void);
        AMateria(std::string const& type);
        AMateria(AMateria const& src);
        AMateria& operator=(AMateria const& rhs);
        std::string const& getType(void)const; //Returns the materia type
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter& target);
};
#endif
