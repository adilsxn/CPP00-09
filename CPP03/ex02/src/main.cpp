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

#include <iostream>
#include "../inc/ClapTrap.hpp"

int	main(void)
{
    ClapTrap se("SnakeEyes");
    ClapTrap j(se);
    j.setName("Jynx");
    ClapTrap ss("StormShadow");
    ClapTrap cc(ss);
    ClapTrap z = ss;
    z.setName("Zartan");
    cc.setName("CobraCommander");

    std::cout << "Duel 1: StormShadow vs SnakeEyes\n";
    for (int i = 0; i < 5 ; i++){
        ss.attack(se.getName());
        se.takeDamage(1);
        se.attack(ss.getName());
        ss.takeDamage(1);
    }
    std::cout <<"SnakeEyes has plot armor\n";
    ss.beRepaired(4);
    se.beRepaired(4);
    cc.attack(se.getName());
    cc.attack(ss.getName());
    cc.attack(j.getName());
    j.attack(cc.getName());
    cc.takeDamage(1);
    j.attack(cc.getName());
    cc.takeDamage(1);
    se.attack(cc.getName());
    cc.takeDamage(1);
    se.attack(ss.getName());
    cc.takeDamage(1);
    ss.takeDamage(2);
    return 0;
} 
