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

#include "../inc/Main.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base::~Base(void){
    return ;
}

Base* generate(void){

    int dice = rand() % 3;
    switch(dice){
    case 0:
       std::cout<<"Generating: A\n";
       return new A();
    case 1:
       std::cout<<"Generating: B\n";
       return new B();
    case 2:
       std::cout<<"Generating: C\n";
       return new C();
    }
    std::cout <<"Error happened: cannot generate a class\n";
    return NULL;
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout <<"Pointer type A\n";
    else if (dynamic_cast<B*>(p))
        std::cout <<"Pointer type B\n";
    else if (dynamic_cast<C*>(p))
        std::cout <<"Pointer type C\n";
    else
        std::cout <<"Invalid Pointer\n";
}

void identify(Base& p){
    try {
        A a = dynamic_cast<A&>(p);
        std::cout <<"Ref. Type A\n";
    }
    catch(std::exception& e){
        std::cout<<"Invalid Ref. Type A: "<<std::endl;
    }
    try {
        B b  = dynamic_cast<B&>(p);
        std::cout <<"Ref. Type B\n";
    }
    catch(std::exception& e){
        std::cout<<"Invalid Ref. Type B: "<<std::endl;
    }
    try {
        C c = dynamic_cast<C&>(p);
        std::cout <<"Ref. Type C\n";
    }
    catch(std::exception& e){
        std::cout<<"Invalid Ref. Type C: "<<std::endl;
    }
}

int	main(void)
{
    std::srand(time(NULL));
    std::cout <<"-----------Correct type-------\n";
    Base* p = generate();
    Base& r = *p; 

    identify(p);
    identify(r);
    delete p;

    std::cout <<"---------Incorrect type-------\n";
    Base* p2 = new Base();
    identify(p2);
    identify(*p2);

    delete p2;
    return 0;
}
