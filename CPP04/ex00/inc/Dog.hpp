#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
    public:
        Dog(void);
        Dog(Dog const& src);
        Dog& operator=(Dog const& rhs);
        void makeSound(void)const;
        ~Dog(void);
};
#endif
