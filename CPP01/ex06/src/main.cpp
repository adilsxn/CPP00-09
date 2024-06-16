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

#include "../inc/Harl.hpp"
#include <iostream>

int	main(int ac, char *av[])
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << "Use as: ./harlFilter [level]"
            <<"Levels are: INFO - DEBUG - WARNING - ERROR\n";
        return 0;
    }
    harl.complain(av[1]);
	return 0;
}
