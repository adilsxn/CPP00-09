#include "../inc/ShrubberyCreationForm.hpp"
#include <exception>
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    :AForm("base", 145, 137),_target("unnamed")
{
    std::cout << "ShrubberyCreationForm default created\n";
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    :AForm("base", 145, 137),_target(target)
{
        std::cout << "ShrubberyCreationForm with target "<<target
            <<" created\n";
        return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
    :AForm(src){
    *this = src;
    std::cout << "ShrubberyCreationForm copy created\n";
    return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs){
    if (this != &rhs)
    {
        this->setTarget(rhs.getTarget());
    }
    std::cout << "ShrubberyCreationForm copy assigned\n";
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor)const{
    try{
        std::string fname(this->getTarget() + "_shrubbery");
        std::ofstream out;

        this->checkRequirements(executor);
        out.open(fname.c_str());
        if (out.fail())
            throw ShrubberyCreationForm::FileCreationException();

        out <<		"		               ,@@@@@@@,\n";
        out <<		"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
        out <<		"    ,&/%/%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
        out <<		"   ,%&/%&&%&&%,@@@/@@@/@@@88\\88888/88'\n";
        out <<		"   %&&%&%&/%&&%@@/@@/ /@@@88888\\88888'\n";
        out <<		"   %&&%/ %&/%/%&&@@/ V /@@' `88\\8 `/88'\n";
        out <<		"   `&%\\ ` /%&'    |.|        \\ '|8'\n";
        out <<		"       |o|        | |         | |\n";
        out <<		"       |.|        | |         | |\n";
        out <<		"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
        std::cout<<"The file "<<fname<<" was created.\n";
        std::cout <<executor.getName()<<" executed "<<this->getName()<<"\n";
        out.close();
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: "<<e.what();
    }
}

void ShrubberyCreationForm::setTarget(std::string const& target){
    this->_target = target;
    return ;
}

std::string ShrubberyCreationForm::getTarget(void)const{
    return this->_target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout <<"ShrubberyCreationForm with target "<<this->_target<<" destroyed\n";
}


const char* ShrubberyCreationForm::FileCreationException::what()const throw(){
    return "Failed to create or open the file\n";
}

