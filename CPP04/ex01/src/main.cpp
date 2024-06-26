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


#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
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
    std::cout << "\n---------In the beginning I made what I was told-------------\n";
    const Animal* meta = new Animal();
    std::cout <<"-----------\n";
    const Animal* j = new Dog();
    std::cout <<"-----------\n";
    const Animal* i = new Cat();
    std::cout <<"-----------\n";
    const WrongAnimal* x = new WrongCat();
    std::cout <<"-----------\n";
    const WrongAnimal* y = new WrongAnimal();
    std::cout << "\n---------Getting the types:-------------\n";
    std::cout << j->getType()<<" "<<std::endl;
    std::cout << i->getType()<<" "<<std::endl;
    std::cout << x->getType()<<" "<<std::endl;
    std::cout << y->getType()<<" "<<std::endl;
    std::cout << "\n-------------Emitting the sound:----------------\n";
    i->makeSound(); //will output the cat sound
    j->makeSound(); //will output the dog sound
    meta->makeSound();
    x->makeSound();
    y->makeSound();
    std::cout << "\n-----------------------------\n";
    Animal* arr[10];
    fillArr(arr, 10);
    std::cout << "\n------------A few animal sounds-----------------\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout <<i<<". ";
        arr[i]->makeSound();
    }
    std::cout<<"\n------------Testing the copies-------------------\n";
    Cat kitty;
    kitty.teachCat("I am every kitty");
    Cat copyKitty(kitty);
    copyKitty.teachCat("Dont cha wish your kitty was freak like me");
    std::cout<<"\n---------The kitty is speaking ----------\n";
    kitty.hunnidMeows();
    std::cout<<"\n---------The copykitty is speaking ----------\n";
    copyKitty.hunnidMeows();
    std::cout<<"\n---------The kitty is speaking again----------\n";
    kitty.hunnidMeows();
    std::cout << "\n---------Deleting the animals in the array-----------\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout <<i<<". \n";
        delete arr[i];
    }
    std::cout << "\n---------Deleting misc animals-----------\n";
    delete meta;
    std::cout <<"\n";
    delete j;
    std::cout <<"\n";
    delete i;
    std::cout <<"\n";
    delete x;
    std::cout <<"\n";
    delete y;
    std::cout <<"\n";
	return (0);
}
