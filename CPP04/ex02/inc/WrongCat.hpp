#ifndef WRONGCAT_HPP 
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    public:
        WrongCat(void);
        WrongCat(WrongCat const& src);
        WrongCat& operator=(WrongCat const& rhs);
         ~WrongCat(void);
        std::string getType(void)const;
        void makeSound(void)const;
};
#endif
