#include <iostream>
#include "../inc/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructed\n";
}

Brain::Brain(Brain const& src){
    std::cout << "Brain copy constructed\n";
    *this = src;
    return ;
}

Brain& Brain::operator=(Brain const& rhs){
    std::cout << "Brain constructed by copy assigment\n";
    if (this != &rhs)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] =  rhs.ideas[i];
    }
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destroyed\n";
}

