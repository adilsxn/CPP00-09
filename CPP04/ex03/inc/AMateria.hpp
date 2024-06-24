#ifndef AMATERIAL_HPP
#define AMATERIAL_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria(void);
        AMateria(std::string const& type);
        AMateria(AMateria const& src);
        AMateria& operator=(AMateria const& rhs);
        virtual ~AMateria(void);
        std::string const& getType(void)const; //Returns the materia type
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter& target);
};
#endif
