#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const& src);
        WrongAnimal& operator=(WrongAnimal const& rhs);
        virtual ~WrongAnimal(void);
        virtual void makeSound(void)const;
        virtual std::string getType(void)const;
        void setType(std::string type);
};
#endif
