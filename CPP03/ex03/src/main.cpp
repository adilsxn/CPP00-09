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
#include "../inc/DiamondTrap.hpp"

int	main(void)
{
    DiamondTrap se("SnakeEyes");
    DiamondTrap ss("StormShadow");

    std::cout << "Duel 1: StormShadow vs SnakeEyes\n\n";

    for (int i = 0; i < 4 ; i++){
        ss.attack(se.getName());
        se.takeDamage(16);
        se.attack(ss.getName());
        ss.takeDamage(16);
    }
    ss.whoAmi();
    se.whoAmi();
    return 0;
} 
