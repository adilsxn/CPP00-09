#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class A_Animal {
    protected:
        std::string _type;
    public:
        A_Animal(void);
        A_Animal(A_Animal const& src);
        A_Animal& operator=(A_Animal const& rhs);
        virtual ~A_Animal(void);
        virtual void makeSound(void)const = 0;
        virtual std::string getType(void)const = 0;
        void setType(std::string type);
};
#endif
