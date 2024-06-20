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
    Base* ret;
    if (dice == 0)
        ret = new A();
    if (dice == 1)
        ret = new B();
    if(dice == 2) 
        ret = new C();
    return ret;
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
        std::cout<<"Invalid Ref. Type A: "<<e.what()<<std::endl;
    }
    try {
        B b  = dynamic_cast<B&>(p);
        std::cout <<"Ref. Type B\n";
    }
    catch(std::exception& e){
        std::cout<<"Invalid Ref. Type B: "<<e.what()<<std::endl;
    }
    try {
        C c = dynamic_cast<C&>(p);
        std::cout <<"Ref. Type C\n";
    }
    catch(std::exception& e){
        std::cout<<"Invalid Ref. Type C: "<<e.what()<<std::endl;
    }
}

int	main(void)
{
    std::cout <<"-----------Correct type-------\n";
    Base* p = generate();
    Base& r = *p; 
    identify(p);
    identify(r);
    delete p;

    std::cout <<"---------Incorrect type-------\n";
    Base* p2 = new Base();
    Base& r2 = *p2; 
    identify(p2);
    identify(r2);
    delete p2;
    return 0;
}
