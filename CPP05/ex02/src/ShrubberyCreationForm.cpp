
#include "../inc/ShrubberyCreationForm.hpp"
#include <exception>
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm():AForm("base", 145, 137),_target("unnamed")
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

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src):AForm(src){
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

void ShrubberyCreationForm::execute(Bureaucrat const& executor){
    try{
        std::string fname(this->getTarget() + "_shrubbery");
        std::ofstream out(fname);
        this->checkRequirements(executor);
        out.open(fname.c_str());
        if (out.fail())
            throw ShrubberyCreationForm::FileCreationException();

        out << R"(
                          _{\ _{\{\/}/}/}__
                         {/{/\}{/{/\}(\}{/\} _
                        {/{/\}{/{/\}(_)\}{/{/\}  _
                     {\{/(\}\}{/{/\}\}{/){/\}\} /\}
                    {/{/(_)/}{\{/)\}{\(_){/}/}/}/}
                   _{\{/{/{\{/{/(_)/}/}/}{\(/}/}/}
                  {/{/{\{\{\(/}{\{\/}/}{\}(_){\/}\}
                  _{\{/{\{/(_)\}/}{/{/{/\}\})\}{/\}
                 {/{/{\{\(/}{/{\{\{\/})/}{\(_)/}/}\}
                  {\{\/}(_){\{\{\/}/}(_){\/}{\/}/})/}
                   {/{\{\/}{/{\{\{\/}/}{\{\/}/}\}(_)
                  {/{\{\/}{/){\{\{\/}/}{\{\(/}/}\}/}
                   {/{\{\/}(_){\{\{\(/}/}{\(_)/}/}\}
                     {/({/{\{/{\{\/}(_){\/}/}\}/}(\}
                      (_){/{\/}{\{\/}/}{\{\)/}/}(_)
                        {/{/{\{\/}{/{\{\{\(_)/}
                         {/{\{\{\/}/}{\{\\}/}
                          {){/ {\/}{\/} \}\}
                          (_)  \.-'.-/
                      __...--- |'-.-'| --...__
               _...--"   .-'   |'-.-'|  ' -.  ""--..__
             -"    ' .  . '    |.'-._| '  . .  '   jro
             .  '-  '    .--'  | '-.'|    .  '  . '
                      ' ..     |'-_.-|
              .  '  .       _.-|-._ -|-._  .  '  .
                          .'   |'- .-|   '.
              ..-'   ' .  '.   `-._.-�   .'  '  - .
               .-' '        '-._______.-'     '  .
                    .      ~,
                .       .   |\   .    ' '-.		
        )" << '\n';
        std::cout<<"The file "<<fname<<" was created.\n";
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

