#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <string>

class ShrubberyCreationForm: public AForm{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(ShrubberyCreationForm const& src);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
        void setTarget(std::string const& target);
        std::string getTarget(void)const;
        void execute(Bureaucrat const& executor)const;
        class FileCreationException: public std::exception{
            virtual const char* what()const throw();
        };
        ~ShrubberyCreationForm(void);
};

#endif

