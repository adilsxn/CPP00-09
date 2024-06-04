#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <ios>
#include <iostream>

Form::Form()
    :_name("unnamed"), _signed(false),
    _gradeToSign(75),_gradeToExecute(75)
{
    std::cout << "Form default created\n";
    return ;
}

Form::Form(std::string const& name, int gradeToSign, int gradeToExec)
    : _name(name)
{
    try {
        std::cout << "Attempting to create a form named: "<<name<<"\n";
        if (gradeToSign < 1 || gradeToExec < 1 )
            throw GradeTooHighException();
        else if (gradeToSign > 150 || gradeToExec > 150 )
            throw GradeTooLowException();
        this->_gradeToExecute = gradeToExec;
        this->_gradeToSign = gradeToSign;
        std::cout << "Form "<<name<<" created\n";
        return ;
    }
    catch(std::exception& e){
        std::cout << "Exception: "<<e.what()<<"\n";
    }
}

Form::Form(Form const& src){
    *this = src;
    std::cout << "Form copy created\n";
    return ;
}


Form& Form::operator=(Form const& rhs){
    if (this != &rhs)
    {
        this->setName(rhs.getName());
        this->setGradeToSign(rhs.getGradeToSign());
        this->setGradeToExecute(rhs.getGradeToExecute());
    }
    std::cout << "Form copy assigned\n";
    return *this;
}

void Form::setName(std::string const& name){
    this->_name = name;
    return ;
}

std::string Form::getName(void)const{
    return this->_name;
}

void  Form::setGradeToExecute(int grade){
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

bool Form::isSigned(void)const{
    return this->_signed;
}

void  Form::setGradeToSign(int grade){
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

int Form::getGradeToSign(void)const{
    return this->_gradeToSign;
}

int Form::getGradeToExecute(void)const{
    return this->_gradeToExecute;
}

Form::~Form(void){
    std::cout <<"Form named "<<this->_name<<" destroyed\n";
}

void Form::beSigned(Bureaucrat const& b){
    try {
        std::cout << "Bureaucrat named "<<b.getName()<<" tries to sign"
            <<" the form named "<<this->getName()<<"\n";
        if (b.getGrade() <= this->getGradeToSign())
            throw Form::GradeTooLowException();
        this->_signed = true;
    }
    catch(std::exception& e){
        std::cout << "Exception: "<<e.what()<<"\n";
    }
}

const char* Form::GradeTooHighException::what()const throw(){
    return "The grade is too high\n";
}

const char* Form::GradeTooLowException::what()const throw(){
    return "The grade is too low\n";
}

std::ostream& operator<<(std::ostream& os, Form const& rhs){
    os <<"Name: "<<rhs.getName()<<"\n- Form signed: "
        << std::boolalpha<< rhs.isSigned()<<"\n- Form grade to sign: "
        <<rhs.getGradeToSign() << "\n- Form grade to execute: "
        <<rhs.getGradeToExecute() << "\n";
    return os;
}
