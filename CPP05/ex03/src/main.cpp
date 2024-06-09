/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/08/06 20:29:18 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>

int	main(void)
{
    {
        std::cout << "\n----------Begin ShrubberyCreationForm --------------\n";
        std::cout << "\n----------Creating Bureaucrats--------------\n";
        Bureaucrat f("Frida", 125);
        Bureaucrat t("Trotsky", 150);
        std::cout <<"\n"<<f;
        std::cout <<t;
        std::cout << "\n----------Creating Forms--------------\n";
        ShrubberyCreationForm s("s");
        ShrubberyCreationForm st("st");
        std::cout << "\n----------Trying to sign the forms--------------\n";
        s.beSigned(f);
        f.signForm(s);
        std::cout << "\n----Executing the forms----\n";
        f.executeForm(s);
        t.executeForm(st);
        std::cout << "\n----------The End--------------\n";
    }
    {
        std::cout << "\n\n----------Begin PresidentialPardonForm --------------\n";
        std::cout << "\n----------Creating Bureaucrats--------------\n";
        Bureaucrat f("Frida", 5);
        Bureaucrat t("Trotsky", 35);
        std::cout <<"\n"<<f;
        std::cout <<t;
        std::cout << "\n----------Creating Forms--------------\n";
        PresidentialPardonForm s("s");
        PresidentialPardonForm st("st");
        std::cout << "\n----------Trying to sign the forms--------------\n";
        s.beSigned(f);
        f.signForm(s);
        f.executeForm(s);
        std::cout << "\n----Executing the forms----\n";
        st.beSigned(f);
        f.signForm(st);
        t.executeForm(st);
        std::cout << "\n----------The End--------------\n";
    }
    {
        std::cout << "\n\n----------Begin RobotomyRequestForm--------------\n";
        std::cout << "\n----------Creating Bureaucrats--------------\n";
        Bureaucrat f("Frida", 5);
        Bureaucrat t("Trotsky", 45);
        std::cout <<"\n"<<f;
        std::cout <<t;
        std::cout << "\n----------Creating Forms--------------\n";
        RobotomyRequestForm s("s");
        RobotomyRequestForm st("st");
        std::cout << "\n----------Trying to sign the forms--------------\n";
        s.beSigned(f);
        f.signForm(s);
        f.executeForm(s);
        std::cout << "\n----Executing the forms----\n";
        st.beSigned(t);
        t.signForm(st);
        t.executeForm(st);
        std::cout << "\n----------The End--------------\n";
    }
    return (0);
}
