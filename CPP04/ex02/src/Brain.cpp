#include <iostream>
#include "../inc/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructed\n";
}

Brain::Brain(Brain const& src){
    std::cout << "Brain copy constructed\n";
    *this = src;
    for(int i = 0; i < 100; i++)
            this->_ideas[i] =  src._ideas[i];
    return ;
}

void Brain::learn(std::string const& lesson){
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = lesson;
    return ;
}

void Brain::speak(void)const{
    for (int i = 0; i < 100; i += 15)
        std::cout << this->_ideas[i] << "\n";
    return ;
}

Brain& Brain::operator=(Brain const& rhs){
    std::cout << "Brain constructed by copy assigment\n";
    if (this != &rhs)
    {
        for(int i = 0; i < 100; i++)
            this->_ideas[i] =  rhs._ideas[i];
    }
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destroyed\n";
}

