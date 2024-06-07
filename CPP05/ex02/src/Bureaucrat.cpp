#include "../inc/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat():_name("robot"), _grade(75){
    std::cout << "Bureaucrat default created\n";
    return ;
}


Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : _name(name){
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
    std::cout << "Bureaucrat "<<name<<" created\n";
    return ;
}


Bureaucrat::Bureaucrat(Bureaucrat const& src){
    *this = src;
    std::cout << "Bureaucrat copy created created\n";
    return ;
}


Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs){
    if (this != &rhs)
    {
        this->setName(rhs.getName());
        this->setGrade(rhs.getGrade());
    }
    std::cout << "Bureaucrat copy assigned\n";
    return *this;
}

void Bureaucrat::setName(std::string const& name){
    this->_name = name;
    return ;
}

std::string Bureaucrat::getName(void)const{
    return this->_name;
}

void Bureaucrat::incrementGrade(void){
    const int lim = 1;
    if (this->_grade > lim)
        this->_grade--;
    else
        throw GradeTooHighException();
    return ;
}

void Bureaucrat::decrementGrade(void){
    const int lim = 150;
    if (this->_grade > lim)
        this->_grade++;
    else
        throw GradeTooLowException();
    return ;
}
int  Bureaucrat::getGrade(void)const{
    return this->_grade;
}

void  Bureaucrat::setGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
    return ;
}

void Bureaucrat::signForm(Form const& f)const{
    if (f.isSigned() == true)
    {
        std::cout <<"The bureaucrat named " << this->getName();
        std::cout <<" signed the form: "<<f.getName();
    }
    else
    {

        std::cout <<"The bureaucrat named " << this->getName();
        std::cout <<" couldn't sign the form: "<<f.getName();
        std::cout << " because the grade is too low\n";
    }
}

Bureaucrat::~Bureaucrat(void){
    std::cout <<"Bureaucrat named "<<this->_name<<" destroyed\n";
}


const char* Bureaucrat::GradeTooHighException::what()const throw(){
    return "The grade is too high, maximum is 1\n";
}

const char* Bureaucrat::GradeTooLowException::what()const throw(){
    return "The grade is too low, minimum is 150\n";
}
std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs){
    os << rhs.getName()<<", bureaucrat grade: "<<rhs.getGrade()<<"\n";
    return os;
}
