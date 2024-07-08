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
#include "../inc/BitcoinExchange.hpp"
int	main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout <<"usage: btc <input.txt>\n";
        return 0;
    }
    try {
    BitcoinExchange btc;
    btc.startExchange(av[1]);
    }
    catch(std::exception& e){
        std::cout <<e.what();
    }
	return (0);
}
