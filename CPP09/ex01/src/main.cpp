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
#include "../inc/RPN.hpp"


int	main(int ac, char **av)
{
    if (ac != 2)
        return std::cout <<"Usage: RPN <postfix expr>\n", 0;
    try{
        RPN::parser(av[1]);
    }
    catch(std::exception& e)
    {
        std::cerr <<e.what();
    }
    return 0;
}
