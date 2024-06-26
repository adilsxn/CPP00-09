#include "../inc/Span.hpp"
#include <algorithm>

Span::Span(void):_maxNum(0), _numbers(0){
    return ;
}

Span::Span(unsigned int n):_maxNum(n){
    return ;
}

Span::Span(const Span& src){
    *this = src;
}

Span& Span::operator=(const Span & rhs){
    if (this != &rhs)
    {
        this->_maxNum = rhs._maxNum;
        this->_numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span(void){
    return ;
}

void Span::addNumber(int number){
    if (_numbers.size() >= _maxNum)
        throw excedingCapacityException();
    _numbers.push_back(number);
    return ;
}


int Span::shortestSpan(void){
    if (_numbers.size() <= 1)
        throw noSpanFoundException();

}

int Span::longestSpan(void){
    if (_numbers.size() <= 1)
        throw noSpanFoundException();
    return std::min_element(_numbers.begin(), _numbers.end()) -
        std::max_element(_numbers.begin(), _numbers.end());
}

const char* Span::excedingCapacityException::what()const throw(){
    return "This span has reached it's capacity\n";
}

const char* Span::noSpanFoundException::what()const throw(){
    return "No span can be found\n";
}
