#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include <exception>
#include <iostream>
#include <string>

Intern::Intern(void){
    std::cout <<"Intern created\n";
}

Intern::Intern(Intern const& src){
    *this = src;
    std::cout <<"Intern copy created\n";
}

Intern& Intern::operator=(Intern const& rhs){
    (void)rhs;
    std::cout <<"Intern copy assigned\n";
    return *this;
}

AForm* Intern::_shrubbery(std::string const& target){
    AForm* form = new ShrubberyCreationForm(target);
    std::cout <<"Intern creates "<<form->getName()<<"\n";
    return form;
}

AForm* Intern::_robotomy(std::string const& target){
    AForm* form = new RobotomyRequestForm(target);
    std::cout <<"Intern creates "<<form->getName()<<"\n";
    return form;
}
AForm* Intern::_presidential(std::string const& target){
    AForm* form = new PresidentialPardonForm(target);
    std::cout <<"Intern creates "<<form->getName()<<"\n";
    return form;
}

const char* Intern::UnknownFormException::what()const throw(){
    return "Unknown form requested.\n";
}

AForm* Intern::makeForm(std::string const& name, std::string const& target){
    AForm* (Intern::*forms[3])(std::string const&) = {
        &Intern::_shrubbery, &Intern::_presidential, &Intern::_robotomy
    };
    std::string names[3] = {
        "shrubbery creation", "presidential pardon", "robotomy request"
    };
    for(int i = 0; i < 3; i++){
        if(!names[i].compare(name))
            return (this->*forms[i])(target);
    }
    throw UnknownFormException();
};

Intern::~Intern(void){
    std::cout <<"Intern destroyed\n";
}
