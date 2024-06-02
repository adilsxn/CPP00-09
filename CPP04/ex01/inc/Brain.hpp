#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain{
    private:
        std::string _ideas[100];
    public:
        Brain(void);
        Brain(Brain const& src);
        void learn(std::string const& lesson);
        void speak(void)const;
        Brain& operator=(Brain const& rhs);
        ~Brain(void);
};
#endif
