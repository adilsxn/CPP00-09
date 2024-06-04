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

#include "../inc/Form.hpp"
// #include "../inc/Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
    //Create Bureaucrats
    std::cout << "\n----------Begin--------------\n";
    std::cout << "\n----------Creating Bureaucrats--------------\n";
    Bureaucrat f("Frida", 65);
    Bureaucrat t("Trotsky", 100);
    // Bureaucrat p("Placeholder", -1);
    // Bureaucrat p2("Another Placeholder", 151);
    std::cout <<"\n"<<f;
    std::cout <<t;

    std::cout << "\n----------Creating Forms--------------\n";
    Form g("good", 75,75);
    Form b("bad", 85, 58);
    Form p3("gradeToSignTooHigh", -1, 149);
    Form p4("gradeToExecTooLow", 1, 151);
    std::cout << "\n--------\n";
    std::cout<<g;
    std::cout<<b;
    std::cout << "\n----------Trying to sign the forms--------------\n";
    g.beSigned(f);
    f.signForm(g);
    std::cout << "\n--------\n";
    b.beSigned(t);
    t.signForm(b);
    std::cout << "\n--------\n";

    std::cout << "\n----------The End--------------\n";
    return (0);
}
