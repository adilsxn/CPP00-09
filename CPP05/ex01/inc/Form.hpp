#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        std::string _name;
        bool _signed;
        int _gradeToSign;
        int _gradeToExecute;
    public:
        Form(void);
        Form(std::string const& name, int gradeToSign, int gradeToExec);
        Form(Form const& src);
        Form& operator=(Form const& rhs);
        void setGradeToSign(int grade);
        void setGradeToExecute(int grade);
        bool isSigned(void)const;
        int getGradeToSign(void)const;
        int getGradeToExecute(void)const;
        void setName(std::string const& name);
        std::string getName(void)const;
        void beSigned(Bureaucrat const& b);
        ~Form(void);
        class GradeTooHighException:public std::exception{
            public:
                virtual const char* what()const throw();
        };
        class GradeTooLowException:public std::exception{
            public:
                virtual const char* what()const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Form const& rhs);
#endif
