#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        std::string _name;
        bool _signed;
        int _gradeToSign;
        int _gradeToExecute;
    public:
        AForm(void);
        AForm(std::string const& name, int gradeToSign, int gradeToExec);
        AForm(AForm const& src);
        AForm& operator=(AForm const& rhs);
        void setGradeToSign(int grade);
        void setGradeToExecute(int grade);
        bool isSigned(void)const;
        int getGradeToSign(void)const;
        virtual void execute(Bureaucrat const& executor) = 0;
        void checkRequirements(Bureaucrat const& b)const;
        int getGradeToExecute(void)const;
        void setName(std::string const& name);
        std::string getName(void)const;
        void beSigned(Bureaucrat const& b);
        ~AForm(void);
        class GradeTooHighException:public std::exception{
            public:
                virtual const char* what()const throw();
        };
        class GradeTooLowException:public std::exception{
            public:
                virtual const char* what()const throw();
        };
        class NotSignedException: public std::exception{
            public:
                virtual const char * what()const throw();
        };
};

std::ostream& operator<<(std::ostream& os, AForm const& rhs);
#endif
