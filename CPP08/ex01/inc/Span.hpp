#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
class Span {
public:
    class excedingCapacityException: public std::exception{
        virtual const char * what(void)const throw(){
            return "This span has reached it's capacity\n";
        }
    };
    Span(void);
    Span(unsigned int n);
    Span(const Span & src);
    Span &operator=(const Span & rhs);
    ~Span(void);
    void addNumber(int number);
    int shortestSpan(void);
    int longestSpan(void);
private:
    std::vector<int> _numbers;
    unsigned int _maxNum;
};

#endif // !DEBUG
