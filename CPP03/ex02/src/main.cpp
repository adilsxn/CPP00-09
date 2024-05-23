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
#include "../inc/FragTrap.hpp"

int	main(void)
{
    FragTrap se("SnakeEyes");
    FragTrap ss("StormShadow");

    ss.highFiveGuys();

    ss.beRepaired(666);
    se.beRepaired(666);

    std::cout << "Duel 1: StormShadow vs SnakeEyes\n";
    for (int i = 0; i < 4 ; i++){
        ss.attack(se.getName());
        se.takeDamage(ss.getAttackDamage());
        se.attack(ss.getName());
        ss.takeDamage(se.getAttackDamage());
    }
    se.highFiveGuys();
    return 0;
} 
