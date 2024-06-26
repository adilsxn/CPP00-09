#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public A_Animal{
    Brain* _brain;
    public:
        Dog(void);
        Dog(Dog const& src);
        Dog& operator=(Dog const& rhs);
        std::string getType(void)const;
        void makeSound(void)const;
        void teachDog(std::string const& lesson);
        void hunnidBarks(void)const;
        virtual ~Dog(void);
};
#endif
