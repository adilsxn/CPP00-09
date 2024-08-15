#include <stack>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include "../inc/RPN.hpp"

RPN::RPN(void){
    return ;
}

RPN::RPN(const RPN& src){
    (void)src;
    return ;
}

RPN& RPN::operator=(const RPN& rhs){
    (void)rhs;
    return *this;
}

RPN::~RPN(void){
    return ;
}


void RPN::parser(const char *input){
    long a, b;
    std::stack<long> st;
    std::string::iterator it;
    std::string s(input);

    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), 
            s.end());
    if (s.find_first_not_of("0123456789+-*/") != std::string::npos)
        throw std::runtime_error("Error: invalid operand\n");
    for(it = s.begin(); it < s.end(); it++)
    {
        std::string ss = "+-*/";
        if (std::isdigit(*it))
            st.push((*it - '0'));
        else if (ss.find(*it) != std::string::npos)
        {
            if (st.size() < 2)
                throw std::runtime_error("Error: insufficient operands\n");
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if (*it == '+')
                st.push(a + b);
            else if (*it == '-')
                st.push(a - b);
            else if (*it == '*')
                st.push(a * b);
            else if (*it == '/')
            {
                if ( b == 0)
                    throw std::runtime_error("Error: division by zero\n");
                st.push(a / b);
            }
        }
        else
        {
            std::cout <<*it<<std::endl;
            throw std::runtime_error("Error: invalid operand\n");
        }
    }
    if (st.size() != 1)
        throw std::runtime_error("Error: invalid expression\n");
    std::cout <<st.top()<<"\n";
}

