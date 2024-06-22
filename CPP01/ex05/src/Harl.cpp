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

void Harl::complain(std::string level){

    int  i = -1;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*fn[4])(void) = {&Harl::_debug, &Harl::_info, 
                                &Harl::_warning,&Harl::_error};

    while(++i < 4)
    {
        if (level == levels[i])
        {
            (this->*fn[i])();
            return ;
        }
    }
    std::cout<<"In time you will that nothing really matters\n";
    return ;
}
