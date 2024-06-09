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

#include "../inc/Intern.hpp"
#include "../inc/Bureaucrat.hpp"
#include <exception>
#include <iostream>

int	main(void)
{
    Intern anIntern;
    {
        std::cout << "\n----------Begin Robotomy--------------\n";
        AForm* frms;
        Bureaucrat f("Frida", 45);
        frms = anIntern.makeForm("robotomy request", "Marx Baby");
        std::cout<<std::endl;
        frms->beSigned(f);
        f.executeForm(*frms);
        std::cout << "\n----------End Robotomy--------------\n";
        delete frms;
    }
    std::cout<<std::endl;
    {
        std::cout << "\n----------Begin Presidential--------------\n";
        AForm* frms;
        Bureaucrat f("Frida", 5);
        frms = anIntern.makeForm("presidential pardon", "Mao Baby");
        std::cout<<std::endl;
        frms->beSigned(f);
        f.executeForm(*frms);
        std::cout << "\n----------End Presidential--------------\n";
        delete frms;
    }
    std::cout<<std::endl;
    {
        std::cout << "\n----------Begin Shrubbery--------------\n";
        AForm* frms;
        Bureaucrat f("Frida", 137);
        frms = anIntern.makeForm("shrubbery creation", "Home Sweet Home");
        std::cout<<std::endl;
        frms->beSigned(f);
        f.executeForm(*frms);
        std::cout << "\n----------End Shrubbery--------------\n";
        delete frms;
    }
    std::cout<<std::endl;
    {
        try{
        std::cout << "\n----------Begin--------------\n";
        AForm* frms;
        Bureaucrat f("Frida", 137);
        frms = anIntern.makeForm("shubbery creation", "Home Sweet Home");
        std::cout << "\n----------The End--------------\n";
        delete frms;
        }
        catch(std::exception& e){
            std::cout<<"Exception: "<<e.what();
        }
    }
    std::cout<<std::endl;
    {
        try{
        std::cout << "\n----------Begin--------------\n";
        AForm* frms;
        Bureaucrat f("Frida", 137);
        frms = anIntern.makeForm("president padron", "Pol Pot");
        std::cout << "\n----------The End--------------\n";
        delete frms;
        }
        catch(std::exception& e){
            std::cout<<"Exception: "<<e.what();
        }
    }
    return (0);
}
