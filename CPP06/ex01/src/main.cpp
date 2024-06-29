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

#include "../inc/Serializer.hpp"
#include <iostream>

int	main(void)
{
    uintptr_t dst = 0;
    Data *ntr = NULL;
    Data *ptr = new Data();

    ptr->name = "Adilson";
    ptr->age = 25;

    std::cout <<"-------Data - before serialization--------\n";
    std::cout <<"Original Pointer: "<<ptr<<"\n";
    std::cout <<"Name:    "<<ptr->name<<"\n";
    std::cout <<"Age:     "<<ptr->age<<std::endl;
    std::cout <<"/////-----Serialization-----////\n";
    dst = Serializer::serialize(ptr);
    std::cout <<"------Serialized pointer: "<<dst<<"\n";
    ntr = Serializer::deserialize(dst);
    std::cout <<"-----Data - after deserialization---------\n";
    std::cout <<"Des Pointer: "<<ntr<<"\n";
    std::cout <<"Des Name:    "<<ntr->name<<"\n";
    std::cout <<"Des Age:     "<<ntr->age<<std::endl;

    delete ptr;
	return (0);
}
