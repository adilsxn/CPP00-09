#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
    std::string _type;
    public:
        Dog(void);
        Dog(Dog const& src);
        Dog& operator=(Dog const& rhs);
        void setType(std::string type);
        std::string getType(void)const;
        void makeSound(void)const;
        virtual ~Dog(void);
};
#endif
