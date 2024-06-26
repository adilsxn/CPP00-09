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

#include <exception>
#include <iostream>
#include <cstdlib>
#include "../inc/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    try{
        std::cout <<"---Default Constructor---\n";
        Array<int> arr1;
        std::cout <<"arr1<int>.size: "<<arr1.size();
        std::cout <<"\n";

        std::cout <<"\n---Parametric Constructor---\n";
        Array<int> arr2(8);
        for(unsigned int i = 0; i < arr2.size(); i++)
            arr2[i] = rand() % 14;
        std::cout <<"arr1<int>.size: "<<arr2.size()<<"\n";
        for(unsigned int i = 0; i < arr2.size(); i++)
            std::cout << arr2[i] <<" | ";
        std::cout <<"\n";
        std::cout <<"\n---Copy Constructor---\n";
        Array<int> arr3(arr2);
        arr3[1] = 4;
        std::cout <<"\narr3<int>.size: "<<arr3.size()<<"\n";
        for(unsigned int i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] <<" | ";
        std::cout <<"\narr2<int>.size: "<<arr3.size()<<"\n";
        for(unsigned int i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] <<" | ";
        std::cout <<"\n";
        std::cout <<"\n---Copy assignment operator---\n";
        Array<int> arr4 = arr3;
        arr4[5] = 5;
        std::cout <<"arr4<int>.size: "<<arr4.size()<<"\n";
        for(unsigned int i = 0; i < arr4.size(); i++)
            std::cout << arr4[i] <<" | ";
        std::cout <<"\n";
        std::cout <<"arr3<int>.size: "<<arr4.size()<<"\n";
        for(unsigned int i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] <<" | ";
        std::cout <<"\n";
        std::cout <<"----This throw an exception: ----\n";
        arr4[arr4.size() + 1];
    }
    catch(std::exception& e){
        std::cout <<e.what()<<"\n";
    }
    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }
    //
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    //
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;//
    return 0;
}

