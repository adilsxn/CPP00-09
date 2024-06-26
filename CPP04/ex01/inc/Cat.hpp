#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
    Brain* _brain;
    public:
        Cat(void);
        Cat(Cat const& src);
        Cat& operator=(Cat const& rhs);
        ~Cat(void);
        std::string getType(void)const;
        void setType(std::string type);
        void teachCat(std::string const& lesson);
        void hunnidMeows(void)const;
        void makeSound(void)const;
};
#endif
