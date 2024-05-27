#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
    std::string _type;
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
