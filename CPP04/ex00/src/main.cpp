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


#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int	main(void)
{

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* x = new WrongCat();
    const WrongAnimal* y = new WrongAnimal();
    std::cout << "\nGetting the types:\n";
    std::cout << j->getType()<<" "<<std::endl;
    std::cout << i->getType()<<" "<<std::endl;
    std::cout << x->getType()<<" "<<std::endl;
    std::cout << y->getType()<<" "<<std::endl;
    std::cout << "\nEmitting the sound:\n";
    i->makeSound(); //will output the cat sound
    std::cout << "\n";
    j->makeSound(); //will output the dog sound
    std::cout << "\n";
    meta->makeSound();
    std::cout << "\n";
    x->makeSound();
    std::cout << "\n";
    y->makeSound();
    std::cout << "\n";
    delete meta;
    delete j;
    delete i;
    delete x;
    delete y;
	return (0);
}
