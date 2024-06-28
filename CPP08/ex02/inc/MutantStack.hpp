#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<stack>
#include<deque>
template<typename T>
class MutantStack: public std::stack<T, std::deque<T>>{
public:
    MutantStack(void){};
    MutantStack(const MutantStack & src):std::stack<T>(src){};
    MutantStack &operator=(const MutantStack & rhs){
        if (this != &rhs)
            this->c = rhs.c;
        return *this;
    };
    ~MutantStack(){
        this->c.clear();
    };

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(){return this->c.begin();}
    iterator end(){ return this->c.end();}
};

#endif // !MUTANTSTACK_HPP
