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

#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
    std::vector<int> v;
    std::vector<int>::const_iterator it;
    
    for(int i = 0; i < 100; i++)
        v.push_back(i);
    try{
        it = easyfind(v, 57);
        std::cout <<"Number found: "<<*it<<"\n";
    }
    catch(std::exception& e){
        std::cout <<e.what();
    }
    try{
        it = easyfind(v, 328);
        std::cout <<"Number found: "<<*it<<"\n";
    }
    catch(std::exception& e){
        std::cout <<e.what();
    }
	return (0);
}
