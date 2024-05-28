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

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include <iostream>

void fillArr(Animal* arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if( i <= 4)
            arr[i] = new Dog();
        else
            arr[i] = new Cat();
    }
}

int	main(void)
{
    Animal* arr[10];
    fillArr(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        std::cout <<i<<". ";
        arr[i]->makeSound();
    }
    std::cout << "\nDeleting the animals\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout <<i<<". ";
        delete arr[i];
    }
	return (0);
}
