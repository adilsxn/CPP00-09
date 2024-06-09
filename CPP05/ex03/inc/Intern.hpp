#ifndef INTERN_HPP
#define INTERN_HPP
#include"AForm.hpp"
#include <exception>
#include <string>
class Intern{
    private:
        AForm* _shrubbery(std::string const& target);
        AForm* _robotomy(std::string const& target);
        AForm* _presidential(std::string const& target);
    public:
        Intern(void);
        Intern(Intern const& src);
        Intern& operator=(Intern const& rhs);
        AForm* makeForm(std::string const& form, std::string const& name);
        class UnknownFormException: public std::exception{
            virtual const char* what()const throw();
        };
        ~Intern(void);

};
#endif
