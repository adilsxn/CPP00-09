
#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45),_target("unnamed")
{
    std::cout << "RobotomyRequestForm default created\n";
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    :AForm("", 72, 45),_target(target)
{
        std::cout << "RobotomyRequestForm with target "<<target
            <<" created\n";
        return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src):AForm(src){
    *this = src;
    std::cout << "RobotomyRequestForm copy created\n";
    return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs){
    if (this != &rhs)
    {
        this->setTarget(rhs.getTarget());
    }
    std::cout << "RobotomyRequestForm copy assigned\n";
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor)const{
    try{
        std::cout <<"Attempting to robotomize the target "<<this->_target
            <<"\n";
        this->checkRequirements(executor);
        std::cout <<"Drilling noises...\n";
        int chances = rand() % 2;
        if (chances == 0)
            std::cout << this->_target<<" has been robotomized sucessfully"
                <<" 50% of the time\n";
        else
            std::cout <<"the robotomy has failed\n";
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: "<<e.what();
    }
}

void RobotomyRequestForm::setTarget(std::string const& target){
    this->_target = target;
    return ;
}

std::string RobotomyRequestForm::getTarget(void)const{
    return this->_target;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout <<"RobotomyRequestForm with target "<<this->_target<<" destroyed\n";
}

