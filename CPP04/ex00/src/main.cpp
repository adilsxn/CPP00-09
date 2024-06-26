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
    {
        std::cout << "=== Wrong Animal by WrongAnimal - b" << std::endl;
		std::cout << "== WrongAnimal" << std::endl;
		const WrongAnimal *	animal = new WrongAnimal();
		std::cout << "WrongAnimal type: " << animal->getType() << std::endl;
		animal->makeSound();
		delete animal;
		std::cout << std::endl;
    }
    {
        std::cout << "=== WrongCat by WrongAnimal - b" << std::endl;
		std::cout << "== WrongAnimal" << std::endl;
		const WrongAnimal *	Cat = new WrongCat();
		std::cout << "WrongAnimal type: " << Cat->getType() << std::endl;
		Cat->makeSound();
		delete Cat;
		std::cout << std::endl;
    }
    {
        std::cout << "=== WrongCat by WrongCat class - b" << std::endl;
		std::cout << "== WrongCat" << std::endl;
		const WrongCat *	Cat = new WrongCat();
		std::cout << "WrongCat type: " << Cat->getType() << std::endl;
		Cat->makeSound();
		delete Cat;
		std::cout << std::endl;
    }
    std::cout <<"//====================================================//\n";
    {
        std::cout << "=== Animal/Cat tests - g" << std::endl;
		std::cout << "== Animal" << std::endl;
		const Animal *	animal = new Animal();
		std::cout << "Animal type: " << animal->getType() << std::endl;
		animal->makeSound();
		delete animal;
		std::cout << std::endl;
    }
    {
        std::cout << "=== Cat by Animal class - g" << std::endl;
		std::cout << "== Animal" << std::endl;
		const Animal *	cat = new Cat();
		std::cout << "Animal type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
    }
    {
        std::cout << "=== Dog by Animal class - g" << std::endl;
		std::cout << "== Animal" << std::endl;
		const Animal *	dog = new Dog();
		std::cout << "WrongCat type: " << dog->getType() << std::endl;
		dog->makeSound();
		delete dog;
		std::cout << std::endl;
    }
    std::cout <<"//====================================================//\n";
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << "\nGetting the types:\n";
        std::cout << j->getType()<<" "<<std::endl;
        std::cout << i->getType()<<" "<<std::endl;
        std::cout << "\nEmitting the sound:\n";
        i->makeSound(); //will output the cat sound
        std::cout << "\n";
        j->makeSound(); //will output the dog sound
        std::cout << "\n";
        meta->makeSound();
        std::cout << "\n";
        delete meta;
        delete j;
        delete i;
    }
    return (0);
}
