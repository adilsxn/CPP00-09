#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
    private:
        std::string _name;
        int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const& src);
        Bureaucrat& operator=(Bureaucrat const& rhs);
        Bureaucrat(std::string const& name, int grade);
        void setName(std::string const& name);
        std::string getName(void)const;
        void setGrade(int grade);
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm const& f)const;
        void executeForm(AForm const& form);
        int  getGrade(void)const;
        ~Bureaucrat(void);
        class GradeTooHighException:public std::exception{
            public:
                virtual const char* what()const throw();
        };

        class GradeTooLowException:public std::exception{
            public:
                const char* what()const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs);
#endif
