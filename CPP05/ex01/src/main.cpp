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

    Bureaucrat f("Frida", 75);
    Bureaucrat t("Trotsky", 100);
    std::cout <<"\n"<<f;
    std::cout <<t;

    Form g("good", 75,75);
    Form ag("silver", 85, 58);
    std::cout<<g;
    std::cout<<ag;

    std::cout << "\n--------\n";
    g.beSigned(f);
    ag.beSigned(t);

    std::cout << "\n--------\n";
    f.signForm(g);
    // t.signForm(ag);

    std::cout << "\n--------\n";

    try{
        Form b("bad", -1, 67);
    }
    catch(const std::exception& e){
        std::cout <<"Exception: "<<e.what();
    }

    std::cout << "\n----------Another attempt--------------\n";
    return (0);
}
