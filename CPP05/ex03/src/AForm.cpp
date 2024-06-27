#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include <ios>
#include <iostream>

AForm::AForm()
    :_name("unnamed"), _signed(false),
    _gradeToSign(75),_gradeToExecute(75)
{
    std::cout << "AForm default created\n";
    return ;
}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExec)
    : _name(name), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{
    try {
        std::cout << "Attempting to create a form named: "<<name<<"\n";
        if (gradeToSign < 1 || gradeToExec < 1 )
            throw GradeTooHighException();
        else if (gradeToSign > 150 || gradeToExec > 150 )
            throw GradeTooLowException();
        this->_gradeToExecute = gradeToExec;
        this->_gradeToSign = gradeToSign;
        std::cout << "AForm "<<name<<" created\n";
        return ;
    }
    catch(std::exception& e){
        std::cout << "Exception: "<<e.what()<<"\n";
    }
}

AForm::AForm(AForm const& src){
    *this = src;
    std::cout << "AForm copy created\n";
    return ;
}


AForm& AForm::operator=(AForm const& rhs){
    if (this != &rhs)
    {
        this->setName(rhs.getName());
        this->setGradeToSign(rhs.getGradeToSign());
        this->setGradeToExecute(rhs.getGradeToExecute());
    }
    std::cout << "AForm copy assigned\n";
    return *this;
}

void AForm::setName(std::string const& name){
    this->_name = name;
    return ;
}

void AForm::checkRequirements(Bureaucrat const& b)const {
    if (isSigned() == false)
        throw AForm::NotSignedException();
    if(b.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    std::cout << b.getName() << " was executed.\n";
}

std::string AForm::getName(void)const{
    return this->_name;
}

void  AForm::setGradeToExecute(int grade){
    try {
        std::cout <<"Trying to set the grade to execute for form"
            <<" named "<<this->getName()<<" to "<<grade<<"\n";
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        this->_gradeToExecute = grade;
    }
    catch(std::exception& e){
        std::cout << "Exception: "<<e.what()<<"\n";
    }
    return ;
}

bool AForm::isSigned(void)const{
    return this->_signed;
}

void  AForm::setGradeToSign(int grade){
    try {
        std::cout <<"Trying to set the grade to sign for form named: "
            <<this->getName()<<" to "<<grade<<"\n";
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        this->_gradeToSign = grade;
    }
    catch(std::exception& e){
        std::cout << "Exception: "<<e.what()<<"\n";
    }
    return ;
}

int AForm::getGradeToSign(void)const{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute(void)const{
    return this->_gradeToExecute;
}

AForm::~AForm(void){
    std::cout <<"AForm named "<<this->_name<<" destroyed\n";
}

void AForm::beSigned(Bureaucrat const& b){
    try {
        std::cout << "Bureaucrat named "<<b.getName()<<" tries to sign"
            <<" the form named "<<this->getName()<<"\n";
        if (b.getGrade() >  this->getGradeToSign())
            throw AForm::GradeTooLowException();
        this->_signed = true;
    }
    catch(std::exception& e){
        std::cout << "Exception: "<<e.what()<<"\n";
    }
}

const char *AForm::NotSignedException::what()const throw(){
    return "The form is not signed\n";
}

const char* AForm::GradeTooHighException::what()const throw(){
    return "The grade is too high\n";
}

const char* AForm::GradeTooLowException::what()const throw(){
    return "The grade is too low\n";
}

std::ostream& operator<<(std::ostream& os, AForm const& rhs){
    os <<"Name: "<<rhs.getName()<<"\n- AForm signed: "
        << std::boolalpha<< rhs.isSigned()<<"\n- AForm grade to sign: "
        <<rhs.getGradeToSign() << "\n- AForm grade to execute: "
        <<rhs.getGradeToExecute() << "\n";
    return os;
}
