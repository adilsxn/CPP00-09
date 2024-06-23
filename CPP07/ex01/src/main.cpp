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
#include "../inc/iter.hpp"
#include <iostream>

void SubOne(char & c){
    c -= 1;
    return ;
}

int	main(void)
{
    {
        std::cout << "-----Int Instanciation test------\n";
        int ArrayofInts[5] = {0, 1, 3, 4, 5};
        size_t size = 5;
        ::printArray(ArrayofInts, size);
        std::cout <<"After iter of mult by 2\n";
        ::iter<int>(ArrayofInts, size, ::multbytwo<int>);
        ::printArray(ArrayofInts, size);
    }
    {
        std::cout << "----- Float Instanciation test------\n";
        float ArrayofFloats[5] = {0.5f, 1.4f, 3.3f, 4.2f, 5.1f};
        size_t size = 5;
        ::printArray(ArrayofFloats, size);
        std::cout <<"After iter of mult by 2\n";
        ::iter<float>(ArrayofFloats, size, ::multbytwo<float>);
        ::printArray(ArrayofFloats, size);
    }
    {
        std::cout << "-----Char Instanciation test------\n";
        char ArrayofChars[5] = {'a', 'b', 'c', 'd', 'e'};
        size_t size = 5;
        ::printArray(ArrayofChars, size);
        std::cout <<"After iter of mult by 2\n";
        ::iter<char>(ArrayofChars, size, SubOne);
        ::printArray(ArrayofChars, size);
    }
	return (0);
}
