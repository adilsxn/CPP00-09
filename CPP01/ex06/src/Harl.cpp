#include "../inc/Harl.hpp"
#include <iostream>

Harl::Harl(void){
    return ;
};

Harl::~Harl(void){
    return ;
}

void Harl::_debug(void){
    std::cout << "[DEBUG]\nI love having extra bacon for my"
        <<" 7XL-double-cheese-triple-pickle-special-ketchup"
        <<" burger. I really do!\n";
}

void Harl::_info(void){
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more "
        <<"money. You didn't put enough bacon in my burger! If you did, "
        <<"I wouldn't be asking for more!\n";
}

void Harl::_warning(void){
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for "
        <<"free. I've been coming for years whereas you started working since" 
        <<" last month.\n";
}

void Harl::_error(void){
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the "
        <<"manager now.\n";
}

void Harl::complain(std::string input){

    int  idx = -1;
    std::string types[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (input == types[i])
        {
            idx = i;
            break ;
        }
    }
    switch(idx)
    {
        case 0:
            this->_debug();
            idx++;
        case 1:
            this->_info();
            idx++;
        case 2:
            this->_warning();
            idx++;
        case 3:
            this->_error();
            break;
        default:
            std::cout <<"Yeah, nothing really matters\n";
    }
}
