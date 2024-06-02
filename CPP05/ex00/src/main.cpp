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

#include "../inc/Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
    try{
        Bureaucrat s;
        s.setName("Somebody's Luv");
        std::cout << s;
        Bureaucrat t("Trotsky", 100);
        std::cout << t;
        Bureaucrat f("Frida", -1);
        std::cout << f;
        t.incrementGrade();
    }
    catch(const std::exception& e){
        std::cout <<"Exception: "<<e.what();
    }
    std::cout << "\n----------Another attempt--------------\n";
    try{

       Bureaucrat l("Lenin", 84);
       Bureaucrat b("Bulgakhov", 34);
       std::cout<<l;
       std::cout<<b;

       l.setGrade(-1);
       b.incrementGrade();

       }
       catch(const std::exception& e){
       std::cout <<"Exception: "<<e.what();
       };
    return (0);
}
