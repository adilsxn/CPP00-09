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
    
    {
    std::cout << "\n----------Beginning--------------\n";
    Bureaucrat s;
    s.setName("Somebody's Luv");
    s.setGrade(150);
    std::cout << s;
    s.decrementGrade();
    std::cout <<"\n----------\n";
    Bureaucrat s1(s);
    s1.setName("Just Luv");
    s1.setGrade(1);
    std::cout << s1;
    s1.incrementGrade();
    std::cout << "\n---------Destructors will come after----------\n";
    }

    std::cout << "\n----------Another Beginning--------------\n";
    Bureaucrat t("Trotsky", 100);
    Bureaucrat f("Frida", 75);
    Bureaucrat b("Bulgakhov", 34);
    Bureaucrat l("Lenin", 84);
    std::cout <<"\n----------\n";
    std::cout << t;
    std::cout << f;
    std::cout << l;
    std::cout << b;
    std::cout <<"\n----------\n";
    l.setGrade(-1);
    b.setGrade(151);
    t.decrementGrade();
    std::cout << t;
    f.incrementGrade();
    std::cout << f;
    std::cout << "\n---------Destructors will come after----------\n";
    return (0);
}
