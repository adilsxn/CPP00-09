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

#include <ctime>
#include <exception>
#include <iostream>
#include "../inc/PmergeMe.hpp"

int	main(int ac, const char *av[])
{
    if (ac == 1)
        return 1;
    try{
        PmergeMe sort(av);
        sort._sortDeq();
        sort._sortVec();
    }
    catch(std::exception& e){
        std::cerr<<e.what()<<std::endl;
    }
	return 0;
}
