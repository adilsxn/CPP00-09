#include "../inc/PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5),_target("unnamed")
{
    std::cout << "PresidentialPardonForm default created\n";
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    :AForm("PresidentialPardonForm", 25, 5),_target(target)
{
        std::cout << "PresidentialPardonForm with target "<<target
            <<" created\n";
        return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src):AForm(src){
    *this = src;
    std::cout << "PresidentialPardonForm copy created\n";
    return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs){
    if (this != &rhs)
    {
        this->setTarget(rhs.getTarget());
    }
    std::cout << "PresidentialPardonForm copy assigned\n";
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor)const{
    try{
        std::cout <<"Attempting to pardon the target "<<this->_target
            <<"\n";
        this->checkRequirements(executor);
        std::cout <<this->_target<<" has been pardoned by Zaphod Beeblebrox"
                <<"\n";
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: "<<e.what();
    }
}

void PresidentialPardonForm::setTarget(std::string const& target){
    this->_target = target;
    return ;
}

std::string PresidentialPardonForm::getTarget(void)const{
    return this->_target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout <<"PresidentialPardonForm with target "<<this->_target<<" destroyed\n";
}

