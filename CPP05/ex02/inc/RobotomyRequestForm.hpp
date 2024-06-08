#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm: public AForm{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string const& target);
        RobotomyRequestForm(RobotomyRequestForm const& src);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
        void setTarget(std::string const& target);
        std::string getTarget(void)const;
        void execute(Bureaucrat const& executor)const;
        ~RobotomyRequestForm(void);
};

#endif
