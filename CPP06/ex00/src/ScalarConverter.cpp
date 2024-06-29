#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter(void)
{
    std::cout <<"ScalarConverter created\n";
    return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const& src)
{
    std::cout <<"ScalarConverter copy created\n";
    (void)src;
    return ;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs)
{
    std::cout <<"ScalarConverter copy assigned\n";
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout <<"ScalarConverter destroyed\n";
    return ;
}

bool isInt(std::string const& input){
    for (size_t i = 0; i < input.length(); i++){
        if (input[i] == '-' || input[i]== '+')
            continue;
        else if(!std::isdigit(input[i]))
            return false;
    }
    return true;
}
bool isChar(std::string const& input){
    if (input.size() == 1 && !std::isdigit(input[0]))
        return true;
    return false;
}

bool isFloat(std::string const& input){
    for (size_t i = 0; i < input.length(); i++){
        if (input[i] == '-' || input[i]== '+')
            continue;
        else if(!std::isdigit(input[i]) && input[i] != '.' 
                && input[i] != 'f')
            return false;
        else if (input[input.length() - 1] != 'f')
            return false;
    }
    return true;
}

bool isDouble(std::string const& input){
    for (size_t i = 0; i < input.length(); i++){
        if (input[i] == '-' || input[i]== '+')
            continue;
        else if(!std::isdigit(input[i]) && input[i] != '.')
            return false;
    }
    return true;
}

bool isPseudo(std::string const& input){
    if (input == "+inff" || input == "-inff" || input == "nanf"
            || input == "-inf" || input == "+inf" || input == "nan")
        return true;
    return false;
}

void toInt(std::string const& input){
    long long  val = static_cast<int>(std::strtoll(input.c_str(), NULL, 10));
    if (val > INT_MAX || val < INT_MIN)
        std::cout <<"int: impossible\n";
    else
        std::cout <<"int: "<<val<<std::endl;
}

void toFloat(std::string const& input){
    float val= static_cast<float>(std::strtof(input.c_str(), NULL));
    std::cout.precision(1);
    if (val > FLT_MAX || val < -FLT_MAX)
        std::cout <<"float: impossible\n";
    else
        std::cout <<"float: "<<std::fixed<<val<<"f"<<std::endl;
}

void toDouble(std::string const& input){
    double val= static_cast<double>(std::strtod(input.c_str(), NULL));
    std::cout.precision(1);
    if (val > DBL_MAX || val < -DBL_MAX)
        std::cout <<"double: impossible\n";
    else
        std::cout <<"double: "<<std::fixed<<val<<std::endl;
}

void toChar(std::string const& input){
    long double val = std::strtold(input.c_str(), NULL);
    char c = static_cast<char>(val);

    if (val > CHAR_MAX || val < CHAR_MIN)
        std::cout <<"char: impossible"<<std::endl;
    else if (std::isprint(c))
        std::cout<<"char: '"<<c<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
}

void CharOnly(std::string const& input){
    if (std::isprint(input[0]))
        std::cout<<"char: '"<<input<<"'"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
    std::cout.precision(1);
    std::cout <<"int:    "<<static_cast<int>(input[0])<<std::endl;
    std::cout <<"float:  "<<std::fixed<<static_cast<float>(input[0])<<"f"<<std::endl;
    std::cout <<"double: "<<std::fixed<<static_cast<double>(input[0])<<std::endl;
}

void toPseudo(std::string const& input){
    if (input[input.size() - 1] != 'f'){
        std::cout << "char: impossible\n"
            <<"int: impossible\n"
            <<"float: "<<input<<"f\n"
            <<"double: "<<input<<std::endl;
    }
    if (input[input.size() - 1] == 'f'){
        std::cout << "char: impossible\n"
            <<"int: impossible\n"
            <<"float: "<<input<<"\n"
            <<"double: "<<input.substr(0, (input.size() - 1))<<std::endl;
    }
}

void ScalarConverter::convert(std::string const& input){
    if (isChar(input))
        CharOnly(input);
    else if (isInt(input) || isFloat(input) || isDouble(input))
    {
        toChar(input);
        toInt(input);
        toFloat(input);
        toDouble(input);
    }
    else if (isPseudo(input))
        toPseudo(input);
    else
    {
        std::cout <<"char: impossible\n"<<"int: impossible\n"
            <<"float: impossible\n"<<"double: impossible"<<std::endl;
    }
}

