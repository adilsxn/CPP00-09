#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal {
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(Animal const& src);
        Animal& operator=(Animal const& rhs);
        virtual ~Animal(void);
        virtual void makeSound(void)const;
        std::string getType(void)const;
        void setType(std::string type);
};
#endif
