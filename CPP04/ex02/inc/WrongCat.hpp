#ifndef WRONGCAT_HPP 
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    std::string _type;
    public:
        WrongCat(void);
        WrongCat(WrongCat const& src);
        WrongCat& operator=(WrongCat const& rhs);
         ~WrongCat(void);
        std::string getType(void)const;
        void setType(std::string type);
        void makeSound(void)const;
};
#endif
