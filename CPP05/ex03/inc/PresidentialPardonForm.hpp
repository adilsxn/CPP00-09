#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm: public AForm{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(PresidentialPardonForm const& src);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
        void setTarget(std::string const& target);
        std::string getTarget(void)const;
        void execute(Bureaucrat const& executor)const;
        ~PresidentialPardonForm(void);
};

#endif
