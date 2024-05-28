#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
    std::string _type;
    Brain* _brain;
    public:
        Cat(void);
        Cat(Cat const& src);
        Cat& operator=(Cat const& rhs);
        virtual ~Cat(void);
        std::string getType(void)const;
        void setType(std::string type);
        void makeSound(void)const;
};
#endif