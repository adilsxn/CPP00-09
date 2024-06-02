#ifndef IMATERIALSOURCE_HPP
#define IMATERIALSOURCE_HPP
#include "AMaterial.hpp"
class IMateriaSource{
    public:
        virtual ~IMateriaSource(){};
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const& type) = 0;
};
#endif
